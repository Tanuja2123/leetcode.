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
    vector<vector<int>> res;
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        if(!root) return res;
        q.push(root);
        bool flag = false;
        while (!q.empty()) {
            int k = q.size();
            vector<int> level(k);
            for (int i = 0; i < k; i++) {
                TreeNode* node = q.front();
                q.pop();
                int idx = (flag)? k-1-i: i;
                level[idx]=node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            flag = !flag;
            res.push_back(level);
        }
        return res;
    }
};