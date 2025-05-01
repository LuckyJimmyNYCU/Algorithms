#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        unordered_set<string> visited;
        queue<pair<string, int>> q;

        if (dead.count("0000")) return -1;

        q.push({"0000", 0});
        visited.insert("0000");

        while (!q.empty()) {
            auto [curr, steps] = q.front();
            q.pop();

            if (curr == target) return steps;

            for (int i = 0; i < 4; ++i) {
                for (int dir : {-1, 1}) {
                    string next = curr;
                    next[i] = (next[i] - '0' + dir + 10) % 10 + '0';
                    if (!dead.count(next) && !visited.count(next)) {
                        visited.insert(next);
                        q.push({next, steps + 1});
                    }
                }
            }
        }

        return -1;
    }
};

int main() {
    Solution sol;

    vector<string> deadends1 = {"0201","0101","0102","1212","2002"};
    string target1 = "0202";
    cout << "Example 1 Output: " << sol.openLock(deadends1, target1) << endl;

    vector<string> deadends2 = {"8888"};
    string target2 = "0009";
    cout << "Example 2 Output: " << sol.openLock(deadends2, target2) << endl;

    vector<string> deadends3 = {"8887","8889","8878","8898","8788","8988","7888","9888"};
    string target3 = "8888";
    cout << "Example 3 Output: " << sol.openLock(deadends3, target3) << endl;

    return 0;
}
