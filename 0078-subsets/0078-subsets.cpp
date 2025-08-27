class Solution {
public:
    vector<vector<int>> res;
    int n;
    void solve(vector<int> temp, vector<int>& nums, int id) {
        res.push_back(temp);
        for (int i = id; i < n; i++) {
            temp.push_back(nums[i]);
            solve(temp, nums, i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
        vector<int> temp;
        solve(temp, nums, 0);
        return res;
    }
};