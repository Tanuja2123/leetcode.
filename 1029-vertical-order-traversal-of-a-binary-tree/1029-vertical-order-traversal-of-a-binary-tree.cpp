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
    vector<vector<int>>res;
    vector<vector<int>> verticalTraversal(TreeNode* root) {
    if(!root) return res;
    map<int, map<int, multiset<int>>>mp;
    queue<tuple<TreeNode*, int,int>>q;
    q.push({root, 0, 0});
    while(!q.empty()){
        auto[node, c, r]= q.front(); q.pop();
        mp[c][r].insert(node->val); //populating map
        if(node->left) q.push({node->left, c-1, r+1});
        if(node->right) q.push({node->right, c+1, r+1});
    }
    for(auto &[col, mpp]: mp ){
        vector<int>vals;
        for(auto &[row, val]: mpp){
            vals.insert(vals.end(), val.begin(), val.end());
        }
        res.push_back(vals);
    }
    return res;
    }
};