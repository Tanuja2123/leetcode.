class Solution {
public:
    vector<vector<int>>res;
    void solve(int k_no, int sum, vector<int>temp, int id){
        if(temp.size()==k_no && sum==0) res.push_back(temp);
        if(temp.size() > k_no || sum<0) return;
        for(int i=id; i<=9; i++){
            temp.push_back(i);
            solve(k_no, sum-i, temp, i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>temp;
        solve(k, n, temp, 1);
        return res;
    }
};