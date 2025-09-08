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
int sum=0;
    TreeNode* solve(TreeNode* root){
        if(!root) return nullptr;
        solve(root->right);
        sum += root->val; //increase the sum /
        root->val=sum; //update the root value
        solve(root->left);
        return root;
    }
    TreeNode* bstToGst(TreeNode* root) {
        return solve(root);
    }
};