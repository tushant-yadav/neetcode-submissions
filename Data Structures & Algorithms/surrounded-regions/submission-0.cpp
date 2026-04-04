class Solution {
    int n , m;
public:

    void fill(vector<vector<char>>& board, int i, int j){
        if(i<0 || i>=n || j<0 || j>=m || board[i][j]!='-') return;
        board[i][j] = 'O';
        fill(board,i-1,j);
        fill(board,i+1,j);
        fill(board,i,j+1);
        fill(board,i,j-1);
    }
    void solve(vector<vector<char>>& board) {
        n = board.size();
        m = board[0].size();
        if(n<3||m<3) return;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O') board[i][j] = '-';
            }
        }

        for(int i=0;i<n;i++){
            fill(board,i,0);
            fill(board,i,m-1);
        }
        for(int j=0;j<m;j++){
            fill(board,0,j);
            fill(board,n-1,j);
        }

                for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='-') board[i][j] = 'X';
            }
        }
    }
};
