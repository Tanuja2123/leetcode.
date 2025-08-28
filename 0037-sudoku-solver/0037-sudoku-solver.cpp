class Solution {
public:
    // combination problem with conditions check
    //  i/3 = gives 0,0,0,1,1,1,2,2,2 for conti number, i%3 gives
    //  0,1,2,0,1,2,0,1,2
    // for loop runs everytime to find the id(start index which it needs to
    // solve to get the '.')
    bool valid(vector<vector<char>>& board, int r, int c, int val) {
        for (int i = 0; i < 9; i++) {
            if (board[r][i] == val)
                return false;
            if (board[i][c] == val)
                return false;
            if (board[3 * (r / 3) + i / 3][3 * (c / 3) + i % 3] == val)
                return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (char c = '1'; c <= '9'; c++) {
                        if (valid(board, i, j, c)) {
                            board[i][j] = c;
                            if (solve(board))
                                return true;
                            board[i][j] = '.';
                        }
                    }
                    return false; // nothing fits from 1 to 9
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) { solve(board); }
};