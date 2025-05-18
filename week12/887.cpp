#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int superEggDrop(int k, int n) {
        // dp[k][n]  k eggs¡An floors
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));

        // base case: 1 egg -> need n tries (linear search)
        for (int j = 1; j <= n; ++j)
            dp[1][j] = j;

        for (int i = 2; i <= k; ++i) {
            for (int j = 1; j <= n; ++j) {
                int low = 1, high = j, res = j;
                while (low <= high) {
                    int mid = (low + high) / 2;
                    int broken = dp[i - 1][mid - 1];    // egg breaks
                    int notBroken = dp[i][j - mid];    // egg doesn't break
                    int temp = 1 + max(broken, notBroken);
                    if (broken > notBroken) {
                        high = mid - 1;
                        res = min(res, temp);
                    } else {
                        low = mid + 1;
                        res = min(res, temp);
                    }
                }
                dp[i][j] = res;
            }
        }

        return dp[k][n];
    }
};

int main() {
    Solution sol;

    // Example 1
    int k1 = 1, n1 = 2;
    cout << "Example 1: " << sol.superEggDrop(k1, n1) << endl; // Output: 2

    // Example 2
    int k2 = 2, n2 = 6;
    cout << "Example 2: " << sol.superEggDrop(k2, n2) << endl; // Output: 3

    // Example 3
    int k3 = 3, n3 = 14;
    cout << "Example 3: " << sol.superEggDrop(k3, n3) << endl; // Output: 4

    return 0;
}
