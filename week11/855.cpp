#include <iostream>
#include <set>
#include <vector>
#include <string>
using namespace std;

class ExamRoom {
private:
    int N;
    set<int> students;

public:
    ExamRoom(int n) {
        N = n;
    }

    int seat() {
        if (students.empty()) {
            students.insert(0);
            return 0;
        }

        int maxDist = *students.begin();
        int seatToAssign = 0;
        int prev = -1;

        for (int s : students) {
            if (prev != -1) {
                int dist = (s - prev) / 2;
                if (dist > maxDist) {
                    maxDist = dist;
                    seatToAssign = prev + dist;
                }
            }
            prev = s;
        }

        if ((N - 1 - *students.rbegin()) > maxDist) {
            seatToAssign = N - 1;
        }

        students.insert(seatToAssign);
        return seatToAssign;
    }

    void leave(int p) {
        students.erase(p);
    }
};

int main() {
    vector<string> commands = {"ExamRoom", "seat", "seat", "seat", "seat", "leave", "seat"};
    vector<vector<int>> params = {{10}, {}, {}, {}, {}, {4}, {}};
    vector<string> output;

    ExamRoom* examRoom = nullptr;

    for (size_t i = 0; i < commands.size(); ++i) {
        if (commands[i] == "ExamRoom") {
            examRoom = new ExamRoom(params[i][0]);
            output.push_back("null");
        } else if (commands[i] == "seat") {
            int res = examRoom->seat();
            output.push_back(to_string(res));
        } else if (commands[i] == "leave") {
            examRoom->leave(params[i][0]);
            output.push_back("null");
        }
    }

    // Print output like LeetCode format
    cout << "[";
    for (size_t i = 0; i < output.size(); ++i) {
        cout << output[i];
        if (i + 1 < output.size()) cout << ", ";
    }
    cout << "]" << endl;

    delete examRoom;
    return 0;
}
