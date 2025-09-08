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
int diff = INT_MIN;
void helper(TreeNode*root, int mini , int maxi)
{
    if( root==NULL) return ;
    if( root->val > maxi)
    {
        maxi = root->val;
    }
    if( root->val < mini)
    {
        mini = root->val;
    }
     if(abs( maxi - mini)> diff)
     {
        diff = maxi -mini;
     }
  helper(root->left, mini , maxi);
  helper( root->right , mini , maxi);
}
    int maxAncestorDiff(TreeNode* root) {
        if( root==NULL)return 0;
        helper( root, INT_MAX, INT_MIN);
        return diff;

    }
};