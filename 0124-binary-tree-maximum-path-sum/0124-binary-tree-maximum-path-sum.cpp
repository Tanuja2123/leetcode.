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
//maxsum returns the maxsum till the node maxsum
    int maxsum;
    int solve(TreeNode* root){
        if(!root) return 0;
        int l=solve(root->left); //solve returns int
        int r=solve(root->right); // 0 if doesn't exist
        int niche_hi= l+r+root->val;
        int koi_ek = max(l,r)+root->val;
        int sirf_root= root->val;
        maxsum=max({maxsum, niche_hi, koi_ek, sirf_root});
        return max(sirf_root, koi_ek);
    }
    int maxPathSum(TreeNode* root) {
       maxsum=INT_MIN;
       solve(root);
       return maxsum;
    }
};