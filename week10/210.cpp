#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // Step 1: setting up graph and array
        vector<vector<int>> graph(numCourses);
        vector<int> inDegree(numCourses, 0);

        for (const auto& pre : prerequisites) {
            int course = pre[0];
            int prereq = pre[1];
            graph[prereq].push_back(course);
            inDegree[course]++;
        }

        // Step 2: finding the course can study immediately
        // inDegree[?]=0  ->  queue
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        // Step 3: order
        vector<int> order;
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            order.push_back(course);

            for (int nextCourse : graph[course]) {
                inDegree[nextCourse]--;
                if (inDegree[nextCourse] == 0) {
                    q.push(nextCourse);
                }
            }
        }

        // Step 4: all the courses can be studied
        if (order.size() == numCourses) {
            return order;
        } else {
            return {}; // can not be studied all courses
        }
    }
};

int main() {
    Solution sol;

    // Example 1
    int numCourses1 = 2;
    vector<vector<int>> prerequisites1 = {{1, 0}};
    vector<int> result1 = sol.findOrder(numCourses1, prerequisites1);
    cout << "Example 1 Output: ";
    for (int course : result1) cout << course << " ";
    cout << endl;

    // Example 2
    int numCourses2 = 4;
    vector<vector<int>> prerequisites2 = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    vector<int> result2 = sol.findOrder(numCourses2, prerequisites2);
    cout << "Example 2 Output: ";
    for (int course : result2) cout << course << " ";
    cout << endl;

    // Example 3
    int numCourses3 = 1;
    vector<vector<int>> prerequisites3 = {};
    vector<int> result3 = sol.findOrder(numCourses3, prerequisites3);
    cout << "Example 3 Output: ";
    for (int course : result3) cout << course << " ";
    cout << endl;

    return 0;
}
