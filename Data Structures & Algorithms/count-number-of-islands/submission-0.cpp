class Solution {
public:

    void dfs(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != '1') {
            return;
        }
        
        grid[i][j] = '0'; // mark as visited
        dfs(grid, i + 1, j); // down
        dfs(grid, i - 1, j); // up
        dfs(grid, i, j + 1); // right
        dfs(grid, i, j - 1); // left
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(n==0 || m==0) return 0;
        int num = 0;
        for(int i=0; i<m;i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]=='1'){
                    dfs(grid, i, j);
                    num++;
                }
            }
        }
        return num;
    }
};