class Solution {
public:
    int res=0;
    void solve(int idx, vector<int>& nums, int k, unordered_map<int, int>&mp){
        //base case
        if(idx >= nums.size()){
            res++;
            return ;
        }
        
        
        //take
        if( !mp[nums[idx]+k] && ! mp[nums[idx]-k]){
            mp[nums[idx]]++;
            solve(idx+1, nums, k,mp);
            mp[nums[idx]]--;
        }
        //not take
        solve(idx+1, nums, k, mp);
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        solve(0, nums, k,mp);
        return res-1; // remove empty subset
    }
};