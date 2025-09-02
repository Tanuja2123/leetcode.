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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode* >q;
        q.push(root);
        bool emptynode=false;
        while(!q.empty()){
            TreeNode* curr= q.front();
            q.pop();
            if(curr == nullptr) {emptynode= true;}
            else {
                if(emptynode) return false;
                 q.push(curr->left); //no left right exist check , if null push it there
                 q.push(curr->right);
            }
        }
        return true;
    }
};