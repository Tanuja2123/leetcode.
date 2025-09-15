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
    int dia;
    int height(TreeNode* root){
        if(!root) return 0;
        int l=height(root->left);
        int r=height(root->right);
        int h=max(l, r)+1;
        dia= max({dia, l+r});
        return h;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        dia=0;
        height( root);
        return dia;
    }
};