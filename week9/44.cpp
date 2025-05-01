#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));

        dp[0][0] = true;

        // initial p is '*'
        for (int j = 1; j <= n; ++j) {
            if (p[j-1] == '*') {
                dp[0][j] = dp[0][j-1];
            }
        }

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j-1] == s[i-1] || p[j-1] == '?') {
                    dp[i][j] = dp[i-1][j-1];
                } else if (p[j-1] == '*') {
                    dp[i][j] = dp[i][j-1] || dp[i-1][j];
                }
            }
        }

        return dp[m][n];
    }
};

int main() {
    Solution sol;

    cout << boolalpha;
    cout << sol.isMatch("aa", "a") << endl; // false
    cout << sol.isMatch("aa", "*") << endl; // true
    cout << sol.isMatch("cb", "?a") << endl; // false
    cout << sol.isMatch("adceb", "*a*b") << endl; // true
    cout << sol.isMatch("acdcb", "a*c?b") << endl; // false

    return 0;
}
