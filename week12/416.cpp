#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for (int num : nums) total += num;

        // if sum is odd, can not be partitioned into equal sum subsets
        if (total % 2 != 0) return false;

        int target = total / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for (int num : nums) {
            for (int i = target; i >= num; i--) {
                dp[i] = dp[i] || dp[i - num];
            }
        }

        return dp[target];
    }
};

int main() {
    Solution solution;

    vector<int> nums1 = {1, 5, 11, 5};
    cout << "Example 1: " << (solution.canPartition(nums1) ? "true" : "false") << endl;

    vector<int> nums2 = {1, 2, 3, 5};
    cout << "Example 2: " << (solution.canPartition(nums2) ? "true" : "false") << endl;

    return 0;
}
