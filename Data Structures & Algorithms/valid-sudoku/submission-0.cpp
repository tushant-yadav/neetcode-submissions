

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        vector<int> row(9);
        vector<int> col(9);
        vector<int> sub(9);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]!='.'){
                    int num = board[i][j]-'0';
                    int mask = (1<<num);
                    int boxidx = (i / 3) * 3 + (j / 3);
                    if((row[i]& mask) || (col[j]&mask) || sub[boxidx]&mask){
                        return 0;
                    }
                    else{
                        row[i] = row[i] | mask;
                        col[j] = col[j] | mask; 
                        sub[boxidx] = sub[boxidx] | mask;
                    }
                 }
            }
        }
        return 1;
        
    }
};
