class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int x1=0,x2=matrix[0].size()-1,y1=0,y2=matrix.size()-1;
        vector<int> ans;

        while(x1<=x2 && y1<=y2){
            for(int i=x1;i<=x2;i++){
                ans.push_back(matrix[y1][i]);
            }
            y1++;

            for(int i=y1;i<=y2;i++){
                ans.push_back(matrix[i][x2]);
            }
            x2--;

            if (y1 <= y2) {
                for (int i = x2; i >= x1; i--) {
                    ans.push_back(matrix[y2][i]);
                }
                y2--;
            }

            // Bottom to Top (Check if column still exists)
            if (x1 <= x2) {
                for (int i = y2; i >= y1; i--) {
                    ans.push_back(matrix[i][x1]);
                }
                x1++;
            }
        }

        return ans;
        
    }
};
