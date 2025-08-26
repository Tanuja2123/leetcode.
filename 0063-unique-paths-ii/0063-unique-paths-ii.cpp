class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& og) {
        int m = og.size(), n = og[0].size();
        if (og[0][0] == 1) return 0; // start blocked

        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;

        // first row
        for(int j = 1; j < n; j++) {
            dp[0][j] = (og[0][j] == 0) ? dp[0][j-1] : 0;
        }

        // first column
        for(int i = 1; i < m; i++) {
            dp[i][0] = (og[i][0] == 0) ? dp[i-1][0] : 0;
        }

        // rest of the grid
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if (og[i][j] == 0)
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                else
                    dp[i][j] = 0;
            }
        }

        return dp[m-1][n-1];
    }
};
