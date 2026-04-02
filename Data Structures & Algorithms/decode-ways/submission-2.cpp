class Solution {
public:
/*
s = 111
1 1 1
11 1
1 11

dp = 1 2 3 0 0 
*/
    int numDecodings(string s) {
        int n = s.length();
        if(n==0 || s[0]=='0') return 0;
        if(n==1) return 1;
        int num = 0;
        vector<int> dp(n+1,0);
        dp[0] = 1;
        dp[1] = s[0]=='0'?0:1;
        for(int i=1;i<=n;i++){
            if(s[i]!='0') dp[i+1] = dp[i];
            if((s[i-1]=='1'||s[i-1]=='2' && s[i]<'7')) dp[i+1] +=dp[i-1];
        }
        return dp[n];
    }
};
