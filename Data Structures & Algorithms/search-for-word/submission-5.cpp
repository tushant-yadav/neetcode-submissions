class Solution {
public:
    int n,m,k;
    bool dfs(vector<vector<char>>& board, string &word, int i, int j, int idx, vector<vector<bool>> &visited){
        if(idx==k) return true;
        if(i<0 || i>=n || j<0 || j>=m || visited[i][j]==1){
            // cout<<"out of bounds"<<endl;
            return false;
        }

        // cout<<i<<":"<<j<<":"<<board[i][j]<<":"<<word[idx]<<idx<<endl;

        if(board[i][j]!=word[idx]) {
            // cout<<"not equal"<<endl;
            return false;
        }
        visited[i][j] =1;
        
        vector<int> x = {0,-1,0,1};
        vector<int> y = {-1,0,1,0};
        for(int a = 0; a<4;a++){
            int new_i = i+y[a], new_j = j+x[a];
            //if(visited[new_i][new_j]) continue;
            if(dfs(board,word,new_i,new_j, idx+1,visited)){
                return true;
            }
        }
        // cout<<"exausted"<<endl;
        visited[i][j] = 0;
        return false;

    }
    bool exist(vector<vector<char>>& board, string word) {
        k = word.size();
        if(word.size() == 0) return true;
        n = board.size(), m = board[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    if(dfs(board, word, i, j, 0,visited)){
                        return true;
                    }
                    // cout<<"returned"<<endl;
                }
            }
        }
        return false;
    }
};
