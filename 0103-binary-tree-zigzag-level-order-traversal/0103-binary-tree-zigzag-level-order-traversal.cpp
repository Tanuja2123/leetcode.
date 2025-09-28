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
    void solve(TreeNode *root) {
        if (!root)
            return;
        queue<TreeNode*> q;
        q.push(root);
        bool flag;
        flag = true; // left to right for first
        while (!q.empty()) {
            int k = q.size();
             // left to right
            vector<int> level(k);

            for (int i = 0; i < k; i++) {
                TreeNode* node = q.front();
                q.pop();
                int idx = (flag)?i : k - 1 - i;
                level[idx] = node->val;
                if (node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            flag=!flag;
            res.push_back(level);
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        solve(root);
        return res;
    }
};