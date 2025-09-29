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
    vector<double>res;
    void solve(TreeNode* root) {
        if (!root)
            return;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int k = q.size();
            long long  sum=0;
            double avg=0;
            int lcount= k;
            while (k--) {
                TreeNode* node = q.front();
                q.pop();
                sum += node->val;
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            avg= (double)sum/lcount;
            res.push_back(avg);
        }
    }
    vector<double> averageOfLevels(TreeNode* root) {
        solve(root);
        return res;
    }
};