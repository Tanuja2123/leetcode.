class Solution {
public:
    vector<vector<int>>res;
    void solve(int target, int len, vector<int>temp, int id){
        if(target <0|| len<0) return;
        if(target==0 && len==0) {
            res.push_back(temp);
            return;
        }
        for(int i=id; i<=9; i++){
            temp.push_back(i);
            solve(target-i, len-1, temp , i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        //k=number int, n=sum
        vector<int>temp;
        solve(n, k, temp, 1);
        return res;
    }
};