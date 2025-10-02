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
    int value;
    bool ans;
    void check(TreeNode* root){
        if(root->val != value) ans= false;
        if(root->left) check(root->left);
        if(root->right) check(root->right);
    }
    bool isUnivalTree(TreeNode* root) {
        if(!root) return true;
        value= root->val;
        ans= true;
        check(root);
        return ans;
    }
};