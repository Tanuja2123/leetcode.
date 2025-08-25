class Solution {
public:
    // backtracking solution
    vector<vector<int>> res;
    int n;
    void solve(vector<int>& nums, int id, vector<int>& temp) {
        if (id >= n) {
            res.push_back(temp);
            return;
        }
        
        temp.push_back(nums[id]);
        solve(nums, id + 1, temp);
        temp.pop_back();
        solve(nums, id + 1, temp);
    }


    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
        res.clear();
        vector<int> temp;
        solve(nums, 0, temp);
        return res;
    }
};