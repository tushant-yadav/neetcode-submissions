class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        if(n==0||m==0) return 0;
        // vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        vector<int> dp(m+1,0);
        for(int i=n-1;i>=0;i--){
            vector<int> temp = dp;
            for(int j=m-1;j>=0;j--){
                if(text1[i]==text2[j]){
                    // dp[i][j] = 1 + dp[i+1][j+1];
                    dp[j] = 1 +  temp[j+1];
                }
                else{
                    dp[j] = max(dp[j+1], temp[j]);
                }
            }
        }
        return dp[0];
        
    }
};
