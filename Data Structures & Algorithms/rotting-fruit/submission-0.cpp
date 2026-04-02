class Solution {
public:

    bool isSafe(int m, int n, int i, int j){
        if(0<=i && i<m && 0<=j && j<n) return 1;
        return 0;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int count = 0;
        int n = grid.size(), m = grid[0].size();
        queue<pair<int,int>> bfs;
        for(int i=0;i<n;i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==2){
                    bfs.push({i,j});
                }
            }
        }

        vector<vector<int>> directions = {{1,0},{0,1},{-1,0},{0,-1}};
        while(!bfs.empty()){
            int size = bfs.size();
            bool flag = 0;

            for(int i=0;i<size;i++){
                pair<int,int> p = bfs.front();
                bfs.pop();
                for(auto dir:directions){
                    int ni = p.first + dir[0];
                    int nj = p.second + dir[1];
                    if(isSafe(n,m,ni,nj) &&  grid[ni][nj] == 1){
                        bfs.push({ni,nj});
                        flag =1;
                        grid[ni][nj] = 2;
                    }
                }
            }
            if(flag ==1) count ++;
        }
        

        for(int i=0;i<n;i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return count;
        
    }
};
