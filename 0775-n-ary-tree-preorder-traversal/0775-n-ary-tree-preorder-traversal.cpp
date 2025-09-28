/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int>res;
    void dfs(Node* root){
        if(!root) return;
        res.push_back(root->val);
        for(Node* child: root->children){
            dfs(child);
        }
    }
    
    vector<int> preorder(Node* root) {
        res.clear();
        dfs(root);
        return res;
    }
};