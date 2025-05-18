#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        if (n == 1) return 0;

        // status (current node, visit node:bitmask)
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(n, vector<bool>(1 << n, false));

        for (int i = 0; i < n; ++i) {
            q.push({i, 1 << i});
            visited[i][1 << i] = true;
        }

        int steps = 0;
        int target = (1 << n) - 1;

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                pair<int, int> cur = q.front();
                q.pop();
                int node = cur.first;
                int mask = cur.second;

                for (int nei : graph[node]) {
                    int next_mask = mask | (1 << nei);
                    if (next_mask == target) return steps + 1;
                    if (!visited[nei][next_mask]) {
                        visited[nei][next_mask] = true;
                        q.push({nei, next_mask});
                    }
                }
            }
            steps++;
        }

        return -1; //no appear
    }
};

int main() {
    Solution sol;

    vector<vector<int>> graph1 = {{1,2,3},{0},{0},{0}};
    cout << "Example 1 Output: " << sol.shortestPathLength(graph1) << endl;

    vector<vector<int>> graph2 = {{1},{0,2,4},{1,3,4},{2},{1,2}};
    cout << "Example 2 Output: " << sol.shortestPathLength(graph2) << endl;

    return 0;
}
