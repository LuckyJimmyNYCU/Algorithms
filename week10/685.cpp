#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1, 0);
        vector<int> candA, candB;

        // Step 1: Detect a node with two parents
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            if (parent[v] == 0) {
                parent[v] = u;
            } else {
                // Found node with two parents
                candA = {parent[v], v};
                candB = {u, v};
                edge[1] = 0;  // Mark as invalid temporarily
            }
        }

        // Step 2: Union-Find
        for (int i = 0; i <= n; ++i) parent[i] = i;

        auto ufind = [&](int u) {
            while (u != parent[u]) {
                parent[u] = parent[parent[u]];  // Path compression
                u = parent[u];
            }
            return u;
        };

        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            if (v == 0) continue;  // Skip invalid edge

            int pu = ufind(u), pv = ufind(v);
            if (pu == pv) {
                if (candA.empty()) return edge;  // Case: cycle, no two parents
                return candA;  // Case: cycle, and node with two parents
            }
            parent[v] = pu;
        }

        return candB;  // Case: no cycle, just remove second edge
    }
};

int main() {
    Solution solution;

    vector<vector<int>> edges1 = {{1, 2}, {1, 3}, {2, 3}};
    vector<int> result1 = solution.findRedundantDirectedConnection(edges1);
    cout << "Output 1: [" << result1[0] << ", " << result1[1] << "]" << endl;

    vector<vector<int>> edges2 = {{1, 2}, {2, 3}, {3, 4}, {4, 1}, {1, 5}};
    vector<int> result2 = solution.findRedundantDirectedConnection(edges2);
    cout << "Output 2: [" << result2[0] << ", " << result2[1] << "]" << endl;

    return 0;
}
