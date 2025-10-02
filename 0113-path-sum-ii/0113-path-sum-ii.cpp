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
    void solve(TreeNode* root, int target, vector<int>temp){
        if(!root){
            return;
        }
        temp.push_back(root->val); //push

        if(!root->left && !root->right && target == root->val){ //check
            res.push_back(temp);
            return;
        }
        //recursive calls
        solve(root->left, target-root->val, temp);
        solve(root->right, target-root->val, temp); //goes till leaf

        //pop_back: not needed since not passed by the reference
        // temp.pop_back(); // recursive call pop backs teh pointers but not the vector since passing by reference
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>temp;
        if(!root) return res;
        solve(root, targetSum, temp);
        return res;
    }
};