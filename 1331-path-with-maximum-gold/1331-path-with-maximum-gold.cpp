class Solution {
public:
    //visit path ones. //backtrack from every-point
    int n,m;
    vector<vector<int>>directions= {{0, 1}, {0, -1}, {1,0}, {-1, 0}};
    int dfs(int i, int j, vector<vector<int>>& grid){
        if(i<0 || j<0 || i>=m|| j>=n || grid[i][j]==0){
            return 0;
        }
        int realval= grid[i][j];
        grid[i][j]=0;
        int maxgold=0; // 0 to update everytime;
        for(auto &d: directions){
            int newi= d[0]+i; int newj= d[1]+j;
            maxgold= max(maxgold ,dfs(newi, newj, grid)); //maxgold 0 here
        }
        grid[i][j]=realval;
        //first call returns the realval., after than keeps returning real val everytime
        return realval+maxgold; // maxgold returned from the inner func calls /recursion
        
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        m=grid.size(), n=grid[0].size();
        int maxgold=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] != 0){
                    maxgold= max(maxgold, dfs(i, j, grid));
                }
            }
        }
        return maxgold;
    }
};