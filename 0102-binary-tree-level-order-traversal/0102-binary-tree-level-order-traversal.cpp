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
    void solve(TreeNode* root){
        if(!root) return;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int k=q.size();
            vector<int>temp;
            while(k--){
                TreeNode* node= q.front(); q.pop();
                temp.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            res.push_back(temp);
        }

    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        solve(root);
        return res;
    }
};