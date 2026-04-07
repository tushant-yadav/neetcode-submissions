class Solution {
/*

 apple penapple
 
*/
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> us(wordDict.begin(), wordDict.end());
        int n = s.length();
        vector<bool> dp(n+1,0);
        dp[0] = 1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<i;j++){
                if(dp[j]==1 && us.find(s.substr(j,i-j))!=us.end()){
                    dp[i] = true;
                }
            }
        }
        return dp[n];

        
    }
};
