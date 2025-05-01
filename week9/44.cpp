#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;

        // final time
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });

        int removeCount = 0;
        int prev_end = intervals[0][1];

        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] < prev_end) {
                // overlappin and delet
                removeCount++;
            } else {
                // non-overlappin, update prev_end
                prev_end = intervals[i][1];
            }
        }

        return removeCount;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> intervals1 = {{1,2},{2,3},{3,4},{1,3}};
    cout << sol.eraseOverlapIntervals(intervals1) << endl; // Output: 1

    vector<vector<int>> intervals2 = {{1,2},{1,2},{1,2}};
    cout << sol.eraseOverlapIntervals(intervals2) << endl; // Output: 2

    vector<vector<int>> intervals3 = {{1,2},{2,3}};
    cout << sol.eraseOverlapIntervals(intervals3) << endl; // Output: 0

    return 0;
}

