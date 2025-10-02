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
    TreeNode* replaceValueInTree(TreeNode* root) {
        if (!root) return nullptr;
        root->val = 0; // root has no cousins
        
        std::queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int sz = q.size();
            long long level_sum = 0;
            
            // collect all nodes of this level
            vector<TreeNode*> level_nodes;
            for (int i = 0; i < sz; ++i) {
                TreeNode* node = q.front(); q.pop();
                level_nodes.push_back(node);
                if (node->left) level_sum += node->left->val;
                if (node->right) level_sum += node->right->val;
            }
            
            // assign new values for children
            for (TreeNode* node : level_nodes) {
                long long sibling_sum = 0;
                if (node->left) sibling_sum += node->left->val;
                if (node->right) sibling_sum += node->right->val;
                
                if (node->left) {
                    node->left->val = level_sum - sibling_sum;
                    q.push(node->left);
                }
                if (node->right) {
                    node->right->val = level_sum - sibling_sum;
                    q.push(node->right);
                }
            }
        }
        
        return root;
    }
};
