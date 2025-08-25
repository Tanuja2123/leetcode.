class Solution {
public:
    vector<vector<int>>res;
    int n;
    void solve (vector<int>&temp, int start, vector<int>&nums){
        res.push_back(temp);
        for(int i=start; i<n; i++){ // not considering start but after start
            if(i>start && nums[i]==nums[i-1] )continue;
            temp.push_back(nums[i]);
            solve(temp, i+1, nums);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        //sorting most imp
        sort(nums.begin(), nums.end());
        n=nums.size();
        vector<int>temp;
        solve(temp, 0, nums);
        return res;
    }
};