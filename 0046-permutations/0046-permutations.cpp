class Solution {
public:
    vector<vector<int>> res;
    unordered_set<int>st;
    int n;
    void solve(vector<int>& nums, vector<int> temp) {
        if (temp.size() == n) {
            res.push_back(temp);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (st.find(nums[i]) == st.end()) {
                temp.push_back(nums[i]); //permutations with numbers
                st.insert(nums[i]);
                solve(nums, temp);
                temp.pop_back();
                st.erase(nums[i]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        vector<int> temp;
        solve(nums, temp);
        return res;
    }
};