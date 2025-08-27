class Solution {
public:
    vector<vector<int>> dirs{{1,0},{-1,0},{0,1},{0,-1}};
    
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size(), n = grid[0].size();
        int totalKeys = 0;
        queue<array<int,4>> q; // {x, y, steps, keyMask}

        // find start and count keys
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == '@') {
                    q.push({r, c, 0, 0});
                } else if (grid[r][c] >= 'a' && grid[r][c] <= 'f') {
                    totalKeys++;
                }
            }
        }

        int fullMask = (1 << totalKeys) - 1;
        vector<vector<vector<char>>> vis(m, vector<vector<char>>(n, vector<char>(fullMask+1, 0)));

        while (!q.empty()) {
            auto [x, y, steps, mask] = q.front(); q.pop();
            if (mask == fullMask) return steps;

            for (auto &d : dirs) {
                int nx = x + d[0], ny = y + d[1];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n || grid[nx][ny] == '#') continue;

                char ch = grid[nx][ny];
                int nmask = mask;

                if (ch >= 'A' && ch <= 'F') { // lock
                    if (((mask >> (ch - 'A')) & 1) == 0) continue; // don’t have key
                }
                if (ch >= 'a' && ch <= 'f') { // key
                    nmask |= (1 << (ch - 'a'));
                }

                if (!vis[nx][ny][nmask]) {
                    vis[nx][ny][nmask] = 1;
                    q.push({nx, ny, steps+1, nmask});
                }
            }
        }
        return -1;
    }


};