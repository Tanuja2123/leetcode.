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
    int ans=INT_MIN;
    int solveh(TreeNode* root){
        if(!root) return 0;
        int l = solveh(root->left);
        int r = solveh(root->right);
        int nichehi= l+r+root->val;
        int koiek= max(r, l)+ root->val;
        int sroot= root->val;
        ans= max({ans, nichehi, koiek, sroot});
        return max(koiek, sroot); //carry back
        
    }
    int maxPathSum(TreeNode* root) {
        solveh(root);
        return ans;
    }
};