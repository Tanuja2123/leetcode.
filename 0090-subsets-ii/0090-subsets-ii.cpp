class Solution {
public:
    vector<vector<int>>res;
    int n;
    void solve(vector<int>temp, vector<int>&nums, int id){
        res.push_back(temp);
        for(int i=id; i<n; i++){
            if(i>id && nums[i]==nums[i-1]) continue;
            temp.push_back(nums[i]);
            solve(temp, nums, i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        n=nums.size();
        sort(nums.begin(), nums.end());

        vector<int>temp;
        solve(temp, nums, 0);
        return res;
    }
};