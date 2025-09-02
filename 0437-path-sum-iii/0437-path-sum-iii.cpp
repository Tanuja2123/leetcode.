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
    unordered_map<long long ,int>presum;
    int dfs(TreeNode* root, long long target, long long csum) {
        if(!root) return 0;
        csum += root->val;
        int count= presum[csum-target];
        //vacktrack
        presum[csum]++;
        count += dfs(root->left, target, csum);
        count += dfs(root->right, target,csum); //target not subtracted in this case
        presum[csum]--;
        return count;
    }

    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;
        presum[0]=1;
        // start from root + recurse on children
        return dfs(root, targetSum, 0) ;
    }
};
