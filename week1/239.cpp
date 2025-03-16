#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> result;
    vector<int> window; // instore 1~k numbers, which indicate the nth in array
    for (int i = 0; i < nums.size(); i++) {
        // if size > k then remove old element
        if (!window.empty() && window.front() == i - k) {
            window.erase(window.begin());
        }

        // new value > window value[a,b], delet window value(b) and look at [a]
        while (!window.empty() && nums[window.back()] < nums[i]) {
            window.pop_back();
        }

        // insert i
        window.push_back(i);

        // we have k numbers to compare
        if (i >= k - 1) {
            result.push_back(nums[window.front()]);
        }
    }

    return result;
}

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> result = maxSlidingWindow(nums, k);

    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
