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
    int solve(TreeNode* root, long long target){
        if(!root) return 0;
        int count =0;
        if(target== root->val) count++;
        count += solve(root->left, target- root->val);
        count += solve(root->right, target- root->val);
        return count;
    }
     int pathSum(TreeNode* root, int targetSum) {
        if(!root ) return 0;
        //o(n^2) to call this function for all the children, left and right called for this function again
        return solve(root, (long long )targetSum) + pathSum(root->right, targetSum) + pathSum(root->left, targetSum);
    }
};