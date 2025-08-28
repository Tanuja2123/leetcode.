class Solution {
public:
    int n, m;
    bool find(vector<vector<char>>&board, string word, int i, int j, int id){
        if(id==word.length()) return true;
        if(i>=n|| i<0 || j>=m || j<0 || board[i][j]!= word[id]) return false;

        char temp= board[i][j];
        board[i][j]= '$';

        if(find(board, word, i-1, j, id+1) || find(board, word, i+1, j, id+1)||
            find(board, word, i, j-1, id+1)|| find(board, word, i, j+1, id+1)){
                return true;
            }
        board[i][j]=temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        n=board.size(), m=board[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]==word[0] && find(board, word, i, j, 0)){
                    return true;
                }
            }
        }
        return false;
    }
};