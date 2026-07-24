class Solution {
public:
    
    void gameOfLife(vector<vector<int>>& board) {
        int i,j,m,n,count=0;
        m = board.size();
        n = board[0].size();
        vector<vector<int>> v = board;
        for(i=0;i<m;++i){
            for(j=0;j<n;++j){
                int count = 0;
                if(i-1 >= 0 && board[i-1][j] == 1) count++;
                if(i+1 < m && board[i+1][j] == 1) count++;
                if(j-1 >= 0 && board[i][j-1] == 1) count++;
                if(j+1 < n && board[i][j+1] == 1) count++;
                if(i-1 >= 0 && j-1 >= 0 && board[i-1][j-1] == 1) count++;
                if(i-1 >= 0 && j+1 < n && board[i-1][j+1] == 1) count++;
                if(i+1 < m && j-1 >= 0 && board[i+1][j-1] == 1) count++;
                if(i+1 < m && j+1 < n && board[i+1][j+1] == 1) count++;
                if(board[i][j] == 1) {
                    if(count < 2 || count > 3)
                        v[i][j] = 0;
                    else
                        v[i][j] = 1;
                }
                else {
                    if(count == 3)
                        v[i][j] = 1;
                    else
                        v[i][j] = 0;
                }

            }
        }
        board = v;
    }
};