class Solution {
public:
    // backtracking solution
    vector<vector<int>> res;
    int n;
    void solve(vector<int>& nums, int id, vector<int>& temp) {
       res.push_back(temp);
       for(int i=id; i<n; i++){
            temp.push_back(nums[i]);
            solve(nums, i+1, temp);
            temp.pop_back();
       }
    }


    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
        res.clear();
        vector<int> temp;
        solve(nums, 0, temp);
        return res;
    }
};