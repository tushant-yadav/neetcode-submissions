class Solution {
    int n,m;
public:

    void dfs(vector<vector<int>>& grid, int i, int j, int count){
        if(i<0||i>=n||j<0||j>=m) return;
        count++;
        if(grid[i][j]<count) return;
        else grid[i][j] = count;
        dfs(grid,i-1,j,count);
        dfs(grid,i+1,j,count);
        dfs(grid,i,j-1,count);
        dfs(grid,i,j+1,count);
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        n = grid.size(); m = grid[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    dfs(grid,i-1,j,0);
                    dfs(grid,i+1,j,0);
                    dfs(grid,i,j-1,0);
                    dfs(grid,i,j+1,0);
                }
            }
        }

        
    }
};
