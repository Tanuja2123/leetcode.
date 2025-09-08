/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int tilt = 0;
    int solve(TreeNode* root) {
        if (!root)
            return 0;
        int l = solve(root->left);
        int r = solve(root->right);
        tilt += abs(l - r); // add for every call
        return root->val + l + r; // return in the last;
    }
    int findTilt(TreeNode* root) {
        solve(root);
        return tilt;
    }
};