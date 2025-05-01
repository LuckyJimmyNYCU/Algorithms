#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        for (int j = 0; j < n; j++) {
            for (int i = n; i >= 0; i--) {
                if (dp[i] == INT_MAX) continue;
                int next = min(n, i + time[j] + 1);
                dp[next] = min(dp[next], dp[i] + cost[j]);
            }
        }

        return dp[n];
    }
};

int main() {
    Solution sol;

    vector<int> cost1 = {1,2,3,2};
    vector<int> time1 = {1,2,3,2};
    cout << sol.paintWalls(cost1, time1) << endl; // Output: 3

    vector<int> cost2 = {2,3,4,2};
    vector<int> time2 = {1,1,1,1};
    cout << sol.paintWalls(cost2, time2) << endl; // Output: 4

    return 0;
}
