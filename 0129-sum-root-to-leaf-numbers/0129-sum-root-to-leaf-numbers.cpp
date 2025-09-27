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
// approach - store the result of number formed at the leaf end of every node.
//after all leaf nodes covered return the sum of l and r, which ultimately returns the sum of the all numbers formed at the leaf nodes
    int solve(TreeNode* root, int csum){
        if(!root) return 0;
        csum = 10*csum+ root->val;
        if(!root->left && !root->right){
            return csum;
        }
        int l= solve(root->left, csum);
        int r=solve(root->right, csum);
        return l+r;
    }
    int sumNumbers(TreeNode* root) {
        return solve(root, 0);

    }
};