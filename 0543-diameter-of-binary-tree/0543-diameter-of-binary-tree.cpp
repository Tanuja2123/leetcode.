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
    int maxi;
    int height(TreeNode* root){
        if(!root) return 0;
        int l=height(root->left);
        int r=height(root->right);
        int twoside= l+r;
        int go_up= max(l, r)+ 1;
        maxi= max({maxi, twoside});
        return go_up;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        maxi=0;
        height(root);
        return maxi;
    }
};