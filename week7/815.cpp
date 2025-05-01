#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;

        // build stop -> routes
        unordered_map<int, vector<int>> stop_to_routes;
        for (int i = 0; i < routes.size(); ++i) {
            for (int stop : routes[i]) {
                stop_to_routes[stop].push_back(i);
            }
        }

        // BFS
        queue<int> q; // bus stops
        unordered_set<int> visited_stops;
        unordered_set<int> visited_routes;
        q.push(source);
        visited_stops.insert(source);

        int buses = 0;
        while (!q.empty()) {
            int size = q.size();
            ++buses;

            for (int i = 0; i < size; ++i) {
                int curr_stop = q.front();
                q.pop();

                for (int route : stop_to_routes[curr_stop]) {
                    if (visited_routes.count(route)) continue;
                    visited_routes.insert(route);

                    for (int next_stop : routes[route]) {
                        if (next_stop == target) return buses;
                        if (!visited_stops.count(next_stop)) {
                            visited_stops.insert(next_stop);
                            q.push(next_stop);
                        }
                    }
                }
            }
        }

        return -1;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> routes1 = {{1, 2, 7}, {3, 6, 7}};
    int source1 = 1, target1 = 6;
    cout << "Example 1 Output: " << sol.numBusesToDestination(routes1, source1, target1) << endl;

    vector<vector<int>> routes2 = {{7, 12}, {4, 5, 15}, {6}, {15, 19}, {9, 12, 13}};
    int source2 = 15, target2 = 12;
    cout << "Example 2 Output: " << sol.numBusesToDestination(routes2, source2, target2) << endl;

    return 0;
}
