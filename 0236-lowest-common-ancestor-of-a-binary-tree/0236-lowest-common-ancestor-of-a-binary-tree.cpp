/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    using tn= TreeNode*;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root==p || root==q) return root;
        tn l= lowestCommonAncestor(root->left, p, q);
        tn r= lowestCommonAncestor(root->right, p, q);
        if(l && r) return root;
        if(l) return l;
        return r;
    }
};