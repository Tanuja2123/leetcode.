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
    int countl(TreeNode* l){
        if(!l)return 0;
        int lh=0;
        while(l){
            l=l->left;
            lh++;
        }
        return lh;
    }
    int countr(TreeNode* r){
        if(!r)return 0;
        int rh=0;
        while(r){
            r=r->right;
            rh++;
        }
        return rh;
    }
    int countNodes(TreeNode* root) {
        int lh= countl(root);
        int rh= countr(root);
        if(lh==rh) return pow(2, lh)-1;
        return countNodes(root->left)+countNodes(root->right)+1;
    }
};