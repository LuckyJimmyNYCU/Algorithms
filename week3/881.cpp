#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end()); // min to max
        int left = 0;
        int right = people.size() - 1;
        int boats = 0;

        while (left <= right) {
            if (people[left] + people[right] <= limit) { // two people on the boats
                left++;
            }
            right--; // the max always go on boats
            boats++;
        }
        return boats;
    }
};

int main() {
    Solution solution;

    vector<int> people1 = {1, 2};
    int limit1 = 3;
    cout << "Output: " << solution.numRescueBoats(people1, limit1) << endl;

    vector<int> people2 = {3, 2, 2, 1};
    int limit2 = 3;
    cout << "Output: " << solution.numRescueBoats(people2, limit2) << endl;

    vector<int> people3 = {3, 5, 3, 4};
    int limit3 = 5;
    cout << "Output: " << solution.numRescueBoats(people3, limit3) << endl;

    return 0;
}
