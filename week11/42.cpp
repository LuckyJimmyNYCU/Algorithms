#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int left_max = 0, right_max = 0;
        int water = 0;

        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] >= left_max)
                    left_max = height[left];
                else
                    water += left_max - height[left];
                left++;
            } else {
                if (height[right] >= right_max)
                    right_max = height[right];
                else
                    water += right_max - height[right];
                right--;
            }
        }

        return water;
    }
};

int main() {
    Solution solution;

    vector<int> example1 = {0,1,0,2,1,0,1,3,2,1,2,1};
    int result1 = solution.trap(example1);
    cout << "Example 1 Output: " << result1 << endl;  // Output: 6

    vector<int> example2 = {4,2,0,3,2,5};
    int result2 = solution.trap(example2);
    cout << "Example 2 Output: " << result2 << endl;  // Output: 9

    return 0;
}
