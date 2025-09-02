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
    vector<vector<int>>res;
    void solve(TreeNode* root, int target, vector<int>path){
        if(!root) return;
        //target <0 condition not here coz target can be negative
        path.push_back(root->val);
        if(!root->right && !root->left && target==root->val){
            res.push_back(path);
            return;
        }
        solve(root->left, target-root->val, path);
        solve(root->right, target-root->val, path);
        path.pop_back(); //pops 7 after reaching null,dead end 5,8,13 comes here to pop
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>path;
        solve(root, targetSum, path);
        return res;
    }
};