#include <iostream>
#include <algorithm>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    int maxSum;
public:
    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        dfs(root);
        return maxSum;
    }

    int dfs(TreeNode* node) {
        if (!node) return 0;

        int leftGain = max(dfs(node->left), 0);  // only take positive paths
        int rightGain = max(dfs(node->right), 0);

        int currentMaxPath = node->val + leftGain + rightGain;

        maxSum = max(maxSum, currentMaxPath);

        return node->val + max(leftGain, rightGain); // single path return
    }
};

// Helper function to build tree for example 1: [1,2,3]
TreeNode* buildExample1() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    return root;
}

// Helper function to build tree for example 2: [-10,9,20,null,null,15,7]
TreeNode* buildExample2() {
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    return root;
}

int main() {
    Solution sol;

    TreeNode* example1 = buildExample1();
    cout << "Example 1 Output: " << sol.maxPathSum(example1) << endl; // Expected: 6

    TreeNode* example2 = buildExample2();
    cout << "Example 2 Output: " << sol.maxPathSum(example2) << endl; // Expected: 42

    return 0;
}
