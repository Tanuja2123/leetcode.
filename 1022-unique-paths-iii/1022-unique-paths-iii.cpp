class Solution {
public:
    int n, m, res = 0, nonobsi = 0;
    vector<vector<int>> dir{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    void backtracking(vector<vector<int>>& grid, int i, int j, int temp) {
        if( i>=n || j>=m || i<0 || j<0 || grid[i][j]==-1 ) return;
        if(grid[i][j]==2){
            if(temp==nonobsi){
                res++;
            }
            return;
        }
        grid[i][j]=-1;
        for(auto &d: dir){
            int newi=i+d[0], newj=j+d[1];
            backtracking(grid, newi, newj, temp+1);
        }
        grid[i][j]=0;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        int starti = 0, startj = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    starti = i;
                    startj = j;
                } else if (grid[i][j] == 0) {
                    nonobsi++;
                } else {
                    continue; // 2-end, -1 -obstacle
                }
            }
        }
        nonobsi++;
        int temp=0;
        backtracking(grid, starti, startj, temp);
        return res;
    }
};