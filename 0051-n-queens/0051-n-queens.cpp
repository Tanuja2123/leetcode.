class Solution {
public:
    int m;
    vector<vector<string>>res;
    vector<bool>col, dig, antidig;
    void solve(vector<string>& temp, int r){
        if(r==m){
            res.push_back(temp);
            return;
        }
        for(int c=0; c<m; c++){
            int d1= r+c, d2= r-c+m-1;
            if(col[c]|| dig[d1] || antidig[d2]) continue;

            col[c]=dig[d1]=antidig[d2]=true; temp[r][c]='Q';
            solve(temp, r+1);
            col[c]=dig[d1]=antidig[d2]=false; temp[r][c]='.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        m=n;
        vector<string>temp(m, string(m, '.'));
        col.assign(m, false);
        dig.assign(m*2-1, false);
        antidig.assign(m*2-1, false);

        solve(temp, 0); //row
        return res;
    }
};