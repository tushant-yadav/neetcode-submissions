class Solution {
public:
    string longestPalindrome(string s) {
/*
  a b a b d 
a 1 0 3 0 0
b 0 1 0 3 0 
a 3 0 1 0 0
b 0 3 0 1 0
d 0 0 0 0 1
*/
        int n = s.length();
        int res = 0, reslen=1;
        vector<vector<bool>> dp(n,vector<bool>(n,0));
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(s[i]==s[j] && (j-i<2 || dp[i+1][j-1])){
                    dp[i][j]=1;
                    if(reslen<(j-i+1)){
                        res = i;
                        reslen = j-i+1;
                    }
                }
            }
        }
        return s.substr(res, reslen);
    }
};
