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
    void solve(TreeNode* root, vector<int>&leaves){
        if(root==nullptr) return;
        if(!root->left && !root->right){
            leaves.push_back(root->val);
            return;
        }
        solve(root->left, leaves);
        solve(root->right, leaves);

    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaves1, leaves2;
        solve(root1, leaves1);
        solve(root2, leaves2);
        return leaves1== leaves2;
    }
};