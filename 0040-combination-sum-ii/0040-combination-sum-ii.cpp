class Solution {
public:
    vector<vector<int>>res;
    int n;
    void solve(vector<int>&c, int t, vector<int>&temp, int id){
        if(t<0) return ;
        if(t==0) res.push_back(temp);
        for(int i=id; i<n; i++){
            if(i>id && c[i]==c[i-1]) continue;
            temp.push_back(c[i]);
            solve(c, t-c[i], temp, i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        n=candidates.size();
        sort(candidates.begin(), candidates.end());
        vector<int>temp;
        solve(candidates, target, temp, 0);
        return res;
    }
};