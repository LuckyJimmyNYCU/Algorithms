#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        int result = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (canFinish(piles, h, mid)) {
                result = mid;
                right = mid - 1;  // Try smaller k
            } else {
                left = mid + 1;   // Need faster k
            }
        }

        return result;
    }

private:
    bool canFinish(const vector<int>& piles, int h, int k) {
        long long hours = 0;
        for (int pile : piles) {
            // cast to long long to avoid overflow
            hours += (static_cast<long long>(pile) + k - 1) / k;
        }
        return hours <= h;
    }
};

int main() {
    Solution sol;

    vector<int> piles1 = {3, 6, 7, 11};
    int h1 = 8;
    cout << "Example 1 Output: " << sol.minEatingSpeed(piles1, h1) << endl;

    vector<int> piles2 = {30, 11, 23, 4, 20};
    int h2 = 5;
    cout << "Example 2 Output: " << sol.minEatingSpeed(piles2, h2) << endl;

    vector<int> piles3 = {30, 11, 23, 4, 20};
    int h3 = 6;
    cout << "Example 3 Output: " << sol.minEatingSpeed(piles3, h3) << endl;

    return 0;
}
