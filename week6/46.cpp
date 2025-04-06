#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> result;

    void backtrack(vector<int> &nums, int start)
    {
        if (start == nums.size())
        {
            result.push_back(nums);
            return;
        }
        for (int i = start; i < nums.size(); i++)
        {
            swap(nums[start], nums[i]); // swap
            backtrack(nums, start + 1); // recursion
            swap(nums[start], nums[i]); // recovery
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        backtrack(nums, 0);
        return result;
    }
};

void printResult(const vector<vector<int>> &permutations)
{
    for (const auto &p : permutations)
    {
        cout << "[";
        for (int i = 0; i < p.size(); ++i)
        {
            cout << p[i];
            if (i != p.size() - 1)
                cout << ",";
        }
        cout << "]" << endl;
    }
    cout << "---------" << endl;
}

int main()
{
    Solution solution;

    vector<int> nums1 = {1, 2, 3};
    cout << "Example 1:" << endl;
    printResult(solution.permute(nums1));

    solution.result.clear(); // clear pre result

    vector<int> nums2 = {0, 1};
    cout << "Example 2:" << endl;
    printResult(solution.permute(nums2));

    solution.result.clear();

    vector<int> nums3 = {1};
    cout << "Example 3:" << endl;
    printResult(solution.permute(nums3));

    return 0;
}
