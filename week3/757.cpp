#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        // 1. sort：look at right from min to max, if right are the same,look at left form max to min
        // sort(intervals.begin(), intervals.end(), lambda function);
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] == b[1] ? a[0] > b[0] : a[1] < b[1];
        });

        int count = 0;
        int first = -1, second = -1;

        // 2. ensure all intervals
        for (const auto& interval : intervals) {
            int left = interval[0], right = interval[1];

            // if intervals has two numbers than break
            if (first >= left && second >= left) {
                continue;
            }

            // if interval exists one number
            if (first >= left) {
                count++;
                second = first;
                first = right;
            }
            // if interval exists no number
            else {
                count += 2;
                second = right - 1;
                first = right;
            }
        }

        return count;
    }
};

int main() {
    Solution solution;

    vector<vector<int>> intervals1 = {{1,3}, {3,7}, {8,9}};
    cout << "Output: " << solution.intersectionSizeTwo(intervals1) << endl;

    vector<vector<int>> intervals2 = {{1,3}, {1,4}, {2,5}, {3,5}};
    cout << "Output: " << solution.intersectionSizeTwo(intervals2) << endl;

    vector<vector<int>> intervals3 = {{1,2}, {2,3}, {2,4}, {4,5}};
    cout << "Output: " << solution.intersectionSizeTwo(intervals3) << endl;

    return 0;
}
