#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> points(n + 2, 1);
        for (int i = 0; i < n; ++i) {
            points[i + 1] = nums[i];
        }

        // dp[i][j]
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        for (int len = 2; len < n + 2; ++len) {
            for (int left = 0; left < n + 2 - len; ++left) {
                int right = left + len;
                for (int k = left + 1; k < right; ++k) {
                    dp[left][right] = max(dp[left][right],
                        dp[left][k] + dp[k][right] + points[left] * points[k] * points[right]);
                }
            }
        }

        return dp[0][n + 1];
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {3, 1, 5, 8};
    cout << "Example 1:\nInput: [3, 1, 5, 8]\nOutput: " << sol.maxCoins(nums1) << endl;

    vector<int> nums2 = {1, 5};
    cout << "Example 2:\nInput: [1, 5]\nOutput: " << sol.maxCoins(nums2) << endl;

    return 0;
}
