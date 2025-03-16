#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size() / 2;
        vector<int> pos(row.size());

        // row[2,3...]  pose[2] = 0
        for (int i = 0; i < row.size(); i++) {
            pos[row[i]] = i;
        }

        int swaps = 0;

        for (int i = 0; i < row.size(); i += 2) {
            int first = row[i];
            // xor
            int second = first ^ 1;

            if (row[i + 1] != second) {
                swaps++;
                int partnerPos = pos[second];

                // swap row[i+1] and row[partnerPos]
                swap(row[i + 1], row[partnerPos]);

                // change pose -> row
                pos[row[partnerPos]] = partnerPos;
                pos[row[i + 1]] = i + 1;
            }
        }

        return swaps;
    }
};

int main() {
    Solution solution;

    vector<int> row1 = {0, 2, 1, 3};
    cout << "Output for Example 1: " << solution.minSwapsCouples(row1) << endl;

    vector<int> row2 = {5, 3, 2, 0, 1, 4};
    cout << "Output for Example 2: " << solution.minSwapsCouples(row2) << endl;

    return 0;
}
