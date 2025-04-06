#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> results;
        vector<string> board(n, string(n, '.'));
        vector<bool> cols(n, false);
        vector<bool> diag1(2 * n - 1, false);
        vector<bool> diag2(2 * n - 1, false);
        backtrack(0, n, board, results, cols, diag1, diag2);
        return results;
    }

private:
    void backtrack(int row, int n, vector<string> &board, vector<vector<string>> &results,
                   vector<bool> &cols, vector<bool> &diag1, vector<bool> &diag2)
    {
        if (row == n)
        {
            results.push_back(board);
            return;
        }

        for (int col = 0; col < n; ++col)
        {
            int d1 = row - col + n - 1;
            int d2 = row + col;
            if (cols[col] || diag1[d1] || diag2[d2])
                continue;

            board[row][col] = 'Q';
            cols[col] = diag1[d1] = diag2[d2] = true;
            backtrack(row + 1, n, board, results, cols, diag1, diag2);
            board[row][col] = '.';
            cols[col] = diag1[d1] = diag2[d2] = false;
        }
    }
};

void printResults(const vector<vector<string>> &results)
{
    for (const auto &solution : results)
    {
        for (const auto &row : solution)
        {
            cout << row << endl;
        }
        cout << "----" << endl;
    }
}

int main()
{
    Solution sol;

    int n1 = 2;
    cout << "Solutions for n = " << n1 << ":\n";
    vector<vector<string>> results1 = sol.solveNQueens(n1);
    printResults(results1);

    int n2 = 5;
    cout << "Solutions for n = " << n2 << ":\n";
    vector<vector<string>> results2 = sol.solveNQueens(n2);
    printResults(results2);

    return 0;
}
