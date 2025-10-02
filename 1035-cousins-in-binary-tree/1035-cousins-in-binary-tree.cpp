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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(): val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *l, TreeNode *r): val(x), left(l), right(r) {}
 * };
 */



class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if (!root) return false;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int sz = q.size();
            bool foundX = false, foundY = false;
            
            for (int i = 0; i < sz; ++i) {
                TreeNode* node = q.front(); q.pop();
                
                // Check if children are x and y (siblings -> not cousins)
                if (node->left && node->right) {
                    if ((node->left->val == x && node->right->val == y) ||
                        (node->left->val == y && node->right->val == x)) {
                        return false;
                    }
                }
                
                if (node->left) {
                    q.push(node->left);
                    if (node->left->val == x) foundX = true;
                    if (node->left->val == y) foundY = true;
                }
                if (node->right) {
                    q.push(node->right);
                    if (node->right->val == x) foundX = true;
                    if (node->right->val == y) foundY = true;
                }
            }
            
            if (foundX && foundY) return true;  // same level, not siblings
            if (foundX || foundY) return false; // only one found
        }
        
        return false;
    }
};
