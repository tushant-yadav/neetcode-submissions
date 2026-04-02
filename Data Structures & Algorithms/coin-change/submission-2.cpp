class Solution {
public:

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> v(n+1,vector<int> (amount+1,INT_MAX-1000));
        for(int i=0;i<n+1;i++){
            v[i][0] = 0;
        }
      
        for(int i=1;i<n+1;i++){
            int coin = coins[i-1];
            for(int j=1;j<amount+1;j++){
                if(j>=coin)                    
                    v[i][j] = min(v[i][j-coin]+1,v[i-1][j]);
                else 
                    v[i][j] = v[i-1][j];
                
            }
        }

        return (v[n][amount]>=INT_MAX-1000)?-1:v[n][amount];
    }
};
