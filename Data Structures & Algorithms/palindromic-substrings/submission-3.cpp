class Solution {

/*
  a b a c
a 1 2 5 
b   1 2 3
a     1 2
c       1
*/
public:
    int countSubstrings(string s) {
        int n = s.length();
        int count = 0;
        vector<vector<bool>> dp(n,vector<bool>(n,0));

        for(int i=n-1;i>=0;i--){
            for(int j = i;j<n;j++){
                if((s[i]==s[j]) && ((j-i<2)||(dp[i+1][j-1]==1))) 
                {
                    dp[i][j] = 1;
                    count++;
                }
            }
        }

        return count;
        
    }
};
