class Solution {
public:
    vector<vector<string>>res;
    int n;
    vector<bool>col, dig, antidig;
    void dfs( int r, vector<string>temp){
        if(r==n){
            res.push_back(temp);
            return;
        }
        for(int c=0; c<n; c++){
            int d1= r+c, d2= r-c+n-1; //n-1 because the it starts from 0
            if(col[c]|| dig[d1]|| antidig[d2]) continue;
            col[c]=dig[d1]=antidig[d2]=true;
            temp[r][c]='Q';
            dfs(r+1, temp);
            col[c]=dig[d1]=antidig[d2]=false;
            temp[r][c]='.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        this->n=n;
        col.assign(n, false);
        dig.assign(n*2-1, false);
        antidig.assign(n*2-1, false);
        int r=0;
        vector<string>temp(n, string(n, '.'));
        dfs( 0, temp);
        return res;
    }
};