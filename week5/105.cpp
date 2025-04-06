#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Solution : binary tree
class Solution
{
public:
    // instore and search
    unordered_map<int, int> inorderIndexMap;
    // point to now dealing
    int preorderIndex = 0;

    // construct tree
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        for (int i = 0; i < inorder.size(); ++i)
        {
            inorderIndexMap[inorder[i]] = i;
        }
        return buildSubTree(preorder, 0, inorder.size() - 1);
    }

private:
    // from inorderLeft to inorderRight
    TreeNode *buildSubTree(vector<int> &preorder, int inorderLeft, int inorderRight)
    {
        // if invalid -> null
        if (inorderLeft > inorderRight)
        {
            return nullptr;
        }

        // find root from preorder
        int rootVal = preorder[preorderIndex++];
        TreeNode *root = new TreeNode(rootVal);

        // from inorderknow left and right
        int inorderRootIndex = inorderIndexMap[rootVal];

        //  inorder construct left tree
        root->left = buildSubTree(preorder, inorderLeft, inorderRootIndex - 1);
        // inorder construct right tree
        root->right = buildSubTree(preorder, inorderRootIndex + 1, inorderRight);

        return root;
    }
};

void printLevelOrder(TreeNode *root)
{
    if (!root)
        return;
    queue<TreeNode *> q;
    vector<string> result;

    q.push(root);
    while (!q.empty())
    {
        TreeNode *curr = q.front();
        q.pop();
        if (curr)
        {
            result.push_back(to_string(curr->val));
            q.push(curr->left);
            q.push(curr->right);
        }
        else
        {
            result.push_back("null");
        }
    }

    while (!result.empty() && result.back() == "null")
    {
        result.pop_back();
    }

    for (size_t i = 0; i < result.size(); ++i)
    {
        cout << result[i];
        if (i != result.size() - 1)
            cout << ",";
    }
    cout << endl;
}

int main()
{
    // Input: preorder and inorder traversal arrays
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    // Solution
    Solution sol;
    TreeNode *root = sol.buildTree(preorder, inorder);

    // Output: [3,9,20,null,null,15,7]
    cout << "Level order traversal of constructed tree:\n";
    printLevelOrder(root);

    return 0;
}
