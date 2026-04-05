class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        if(n==0||m==0) return 0;
        if(m>n){
            swap(text1,text2);
            swap(m,n);
        }
        vector<int> dp(m+1,0);
        for(int i=n-1;i>=0;i--){
            int prev_dia = 0;
            for(int j=m-1;j>=0;j--){
                int temp = dp[j];
                if(text1[i]==text2[j]){
                    dp[j] = 1 + prev_dia;
                }
                else{
                    dp[j] = max(dp[j+1], dp[j]);
                }
                prev_dia = temp;
            }
        }
        return dp[0];
    }
};
