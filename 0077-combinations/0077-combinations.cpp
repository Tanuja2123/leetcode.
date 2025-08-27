class Solution {
public:
    vector<vector<int>>res;
    void solve(int n, int k, vector<int>temp, int id){
        if(k==0){
            res.push_back(temp);
            return;
        }
        for(int i=id; i<=n; i++){ // start from 2 to avoid reoccurence/duplicates
            temp.push_back(i);
            solve(n, k-1, temp, i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>temp;
        solve(n, k, temp, 1);
        return res;
    }
};