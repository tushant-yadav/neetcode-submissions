class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n,vector<bool>(n,0));
        int res=0, reslen=1;

        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(s[i]==s[j] && (j-i<2||dp[i+1][j-1])){
                    dp[i][j]=1;
                    if(reslen<(j-i+1)){
                        res = i;
                        reslen = j-i+1;
                    }
                }
            }
        }
        return s.substr(res,reslen);

        
    }
};
