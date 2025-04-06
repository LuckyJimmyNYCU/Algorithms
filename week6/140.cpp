#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    // main：recursion and return all results
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        unordered_map<string, vector<string>> memo;
        return backtrack(s, dict, memo);
    }

private:
    // recursion + memory search
    vector<string> backtrack(const string &s, unordered_set<string> &dict, unordered_map<string, vector<string>> &memo)
    {
        if (memo.count(s))
            return memo[s];
        vector<string> result;

        if (s.empty())
            return {""};

        for (int i = 1; i <= s.size(); ++i)
        {
            string word = s.substr(0, i);
            if (dict.count(word))
            {
                vector<string> rest = backtrack(s.substr(i), dict, memo);
                for (const string &sentence : rest)
                {
                    result.push_back(word + (sentence.empty() ? "" : " ") + sentence);
                }
            }
        }

        memo[s] = result;
        return result;
    }
};

int main()
{
    Solution sol;

    string s1 = "catsanddog";
    vector<string> dict1 = {"cat", "cats", "and", "sand", "dog"};
    vector<string> result1 = sol.wordBreak(s1, dict1);
    cout << "Example 1 output:\n";
    for (const string &str : result1)
    {
        cout << "\"" << str << "\"" << endl;
    }

    string s2 = "pineapplepenapple";
    vector<string> dict2 = {"apple", "pen", "applepen", "pine", "pineapple"};
    vector<string> result2 = sol.wordBreak(s2, dict2);
    cout << "\nExample 2 output:\n";
    for (const string &str : result2)
    {
        cout << "\"" << str << "\"" << endl;
    }

    string s3 = "catsandog";
    vector<string> dict3 = {"cats", "dog", "sand", "and", "cat"};
    vector<string> result3 = sol.wordBreak(s3, dict3);
    cout << "\nExample 3 output:\n";
    for (const string &str : result3)
    {
        cout << "\"" << str << "\"" << endl;
    }

    return 0;
}
