#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1); // each child at least one candy

        // ensure right child candy is more than left if right score is more than left
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        // ensure left child candy is more than right if left score is more than right
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }

        // get all candies 0+candies[0]+candiex[1].......
        return accumulate(candies.begin(), candies.end(), 0);
    }
};

int main() {
    Solution solution;

    vector<int> ratings1 = {1, 0, 2};
    cout << "Output: " << solution.candy(ratings1) << endl;

    vector<int> ratings2 = {1, 2, 2};
    cout << "Output: " << solution.candy(ratings2) << endl;

    return 0;
}
