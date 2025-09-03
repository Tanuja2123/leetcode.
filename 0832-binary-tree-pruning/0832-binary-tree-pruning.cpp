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
//it can have 0-1-0 so dont prune based on left or right but on the basis of root->val if that is zero and left right doen't exist then pruneit 
    TreeNode* solve(TreeNode* root){
        if(!root) return nullptr;
        root->left= solve(root->left); //last case before nullptr
        root->right= solve(root->right);
        if(root->val==0 && !root->left && !root->right){
            return nullptr;
        }
        return root; // if null already not returned
    }
    TreeNode* pruneTree(TreeNode* root) {
        return solve(root);
        
    }
};