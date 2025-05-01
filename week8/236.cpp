#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (left && right) return root;
        return left ? left : right;
    }
};

// Helper to build tree manually for examples
TreeNode* buildExampleTree() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    return root;
}

int main() {
    Solution sol;

    // Example 1
    TreeNode* root1 = buildExampleTree();
    TreeNode* p1 = root1->left;  // 5
    TreeNode* q1 = root1->right; // 1
    TreeNode* lca1 = sol.lowestCommonAncestor(root1, p1, q1);
    cout << "Example 1 Output: " << lca1->val << endl; // 3

    // Example 2
    TreeNode* root2 = buildExampleTree();
    TreeNode* p2 = root2->left; // 5
    TreeNode* q2 = root2->left->right->right; // 4
    TreeNode* lca2 = sol.lowestCommonAncestor(root2, p2, q2);
    cout << "Example 2 Output: " << lca2->val << endl; // 5

    // Example 3
    TreeNode* root3 = new TreeNode(1);
    root3->left = new TreeNode(2);
    TreeNode* p3 = root3;       // 1
    TreeNode* q3 = root3->left; // 2
    TreeNode* lca3 = sol.lowestCommonAncestor(root3, p3, q3);
    cout << "Example 3 Output: " << lca3->val << endl; // 1

    return 0;
}
