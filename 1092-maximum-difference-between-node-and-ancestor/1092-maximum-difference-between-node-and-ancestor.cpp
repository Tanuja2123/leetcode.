/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int diff = INT_MIN;
    void solve(TreeNode* root, int mini, int maxi){
        if(!root) return ;
        if(root->val < mini) mini= root->val;
        if(root->val > maxi) maxi= root->val;
        diff= max(diff, abs(maxi-mini));
        solve(root->left, mini, maxi);
        solve(root->right, mini, maxi);
    }
    int maxAncestorDiff(TreeNode* root) {
        solve(root,INT_MAX, INT_MIN);
        return diff;
    }
};