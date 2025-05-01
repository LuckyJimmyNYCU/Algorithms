#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> tree;
    vector<int> res, count;

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        tree.resize(n);
        res.resize(n);
        count.resize(n, 1);  // node self

        // builld tree
        for (auto& e : edges) {
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
        }

        // 1st DFS¡Gcauclate form down to up
        dfs1(0, -1);

        // 2nd DFS¡Gcauclate form up to down
        dfs2(0, -1, n);

        return res;
    }

    void dfs1(int node, int parent) {
        for (int child : tree[node]) {
            if (child == parent) continue;
            dfs1(child, node);
            count[node] += count[child];
            res[node] += res[child] + count[child];
        }
    }

    void dfs2(int node, int parent, int n) {
        for (int child : tree[node]) {
            if (child == parent) continue;
            res[child] = res[node] - count[child] + (n - count[child]);
            dfs2(child, node, n);
        }
    }
};

int main() {
    {
        Solution sol;
        vector<vector<int>> edges1 = {{0,1},{0,2},{2,3},{2,4},{2,5}};
        vector<int> res1 = sol.sumOfDistancesInTree(6, edges1);
        for (int x : res1) cout << x << " ";
        cout << endl; // Output: 8 12 6 10 10 10
    }

    {
        Solution sol;
        vector<vector<int>> edges2 = {};
        vector<int> res2 = sol.sumOfDistancesInTree(1, edges2);
        for (int x : res2) cout << x << " ";
        cout << endl; // Output: 0
    }

    {
        Solution sol;
        vector<vector<int>> edges3 = {{1,0}};
        vector<int> res3 = sol.sumOfDistancesInTree(2, edges3);
        for (int x : res3) cout << x << " ";
        cout << endl; // Output: 1 1
    }

    return 0;
}

