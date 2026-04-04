class Solution {
    unordered_map<int,int> um;
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0) return 0;
        if(um.find(amount)!=um.end()) return um[amount];
        int res = 10000;

        for(int coin:coins){
            if(amount<coin) continue;
            int ret = coinChange(coins,amount-coin);
            res = min(res, ret==-1?10000:ret+1);
        }
            um[amount] = res;
            return res>=10000?-1:res;
    }
};
