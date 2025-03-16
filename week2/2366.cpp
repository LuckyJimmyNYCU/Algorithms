#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n = nums.size();
        long long operations = 0;
        int prev = nums[n - 1]; // selecting the last number, because last number >= front number

        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] > prev) { // orther number > last number
                int parts = (nums[i] + prev - 1) / prev; // caculate "n" divide
                operations += (parts - 1); // we have (parts - 1) times operation
                prev = nums[i] / parts; //update prev number
            } else {
                prev = nums[i]; // do not need to divide, iust update prev
            }
        }

        return operations;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {5, 2, 4, 7};
    vector<int> nums2 = {3, 10, 3};

    cout << "Example 1: " << sol.minimumReplacement(nums1) << endl;
    cout << "Example 2: " << sol.minimumReplacement(nums2) << endl;

    return 0;
}
