#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0; // if only 0/1 element return 0
        int jumps = 0; // jump times
        int curr_end = 0; // the max distance this step
        int farthest = 0; // the max distance

        for (int i = 0; i < n - 1; i++) {
            farthest = max(farthest, i + nums[i]); // get now max distance

            if (i == curr_end) {
                jumps++;
                curr_end = farthest;

                if (curr_end >= n - 1) { // arrive final point
                        break;
                }
            }
        }
        return jumps;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {2, 3, 1, 1, 4};
    vector<int> nums2 = {2, 3, 0, 1, 4};

    cout << "Example 1: " << sol.jump(nums1) << endl;
    cout << "Example 2: " << sol.jump(nums2) << endl;

    return 0;
}
