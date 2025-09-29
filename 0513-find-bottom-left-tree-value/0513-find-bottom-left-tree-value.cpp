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
    int solve(TreeNode* root) {
        if(!root) return -1;
        queue<TreeNode*>q;
        q.push(root);
        int last=root->val;
        while(!q.empty()){
            int k=q.size();
            for(int i=0; i<k; i++){
                TreeNode* node= q.front(); q.pop();
                if(i==0) last=node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        return last;
    }
    int findBottomLeftValue(TreeNode* root) {
        return solve(root);
    }
};