// class Solution {
// public:
//     int maxAreaOfIsland(vector<vector<int>>& grid) {
        
//     }
// };

class Solution {
    int n,m;
public:

    int dfs(vector<vector<int>>& grid, int i, int j){
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j]==0) return 0;
        grid[i][j] = 0;
        return dfs(grid,i-1,j)+dfs(grid,i+1,j)+dfs(grid,i,j-1)+dfs(grid,i,j+1) +1;

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size(); m=grid[0].size();
        int area = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    area = max(area,dfs(grid,i,j));
                }
            }
        }
        return area;
        
    }
};
