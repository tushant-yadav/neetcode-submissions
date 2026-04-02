class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int n = matrix.size(),m=matrix[0].size();
        vector<pair<int,int>> zeros;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    zeros.push_back({i,j});
                }
                
            }
        
        }
        for(auto k:zeros){
            for(int i=0;i<n;i++) matrix[i][k.second]=0;
            for(int j=0;j<m;j++) matrix[k.first][j]=0;
        }
    }
};