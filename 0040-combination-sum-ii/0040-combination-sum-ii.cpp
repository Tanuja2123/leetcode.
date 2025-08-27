class Solution {
public:
    vector<vector<int>>res;
    int n;
    void solve(vector<int>&c, int target, vector<int>temp, int id){
        if(target<0) return;
        if(target==0) {
            res.push_back(temp);  
        }
        for(int i=id; i<n; i++){
            if(i>id && c[i]==c[i-1])continue;
            temp.push_back(c[i]);
            solve(c, target-c[i], temp, i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        n=candidates.size();
        vector<int>temp;
        sort(candidates.begin(), candidates.end());
        solve(candidates, target, temp, 0);
        return res;
    }
};