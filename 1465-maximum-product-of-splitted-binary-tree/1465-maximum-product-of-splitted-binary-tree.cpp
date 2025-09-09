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
    long long tsum=0;
    long long maxi=0;
    const int mod= 1e9+7;
    long long fsum(TreeNode* root){
        if(!root) return 0;
        return root->val + fsum(root->left)+ fsum(root->right);
    }
    long long dfs(TreeNode* root){
        if(!root) return 0;
        long long l= dfs(root->left);
        long long r=dfs(root->right);
        long long csum= root->val+r+l;
        maxi= max(csum * (tsum-csum), maxi);
        return csum;
    }
    int maxProduct(TreeNode* root) {
        tsum= fsum(root);
        dfs(root);
        return maxi % mod;
    }
};