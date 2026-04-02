class Solution {
public:

    void dfs(vector<vector<bool>> &ocean, int i, int j, int ph, vector<vector<int>> &ht){
        int n = ht.size(); int m = ht[0].size();
        if(i<0 || j<0|| i>=n || j>=m || ocean[i][j] || ph > ht[i][j]) 
            return;

        ocean[i][j] = 1;
        dfs(ocean,i-1,j,ht[i][j],ht);
        dfs(ocean,i,j-1,ht[i][j],ht);
        dfs(ocean,i+1,j,ht[i][j],ht);
        dfs(ocean,i,j+1,ht[i][j],ht);
        return;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& ht) {
        int n = ht.size();
        int m = ht[0].size();
        vector<vector<bool>> atl(n,vector<bool>(m,0));        
        vector<vector<bool>> pac(n,vector<bool>(m,0));

        for(int i=0;i<n;i++){
            dfs(pac, i, 0, ht[i][0],ht);
            dfs(atl, i, m-1, ht[i][m-1], ht);
        }

        for(int j=0;j<m;j++){
            dfs(pac,0,j,ht[0][j],ht);
            dfs(atl,n-1,j,ht[n-1][j],ht);
        }
        vector<vector<int>> res;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(atl[i][j] && pac[i][j]){
                    res.push_back({i,j});
                }
            }
        }
        return res;
    }
};
