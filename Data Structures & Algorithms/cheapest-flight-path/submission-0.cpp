class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> prices(n,INT_MAX);
        prices[src] = 0;

        for(int i = 0;i<=k;i++){
            vector<int> temp = prices;

            for(auto f:flights){
                int u = f[0], v = f[1], distance = f[2];
                if(prices[u]<INT_MAX){
                    temp[v]= min(temp[v],prices[u]+distance);
                }
            }
            prices = temp;
        }
        return prices[dst]==INT_MAX?-1:prices[dst];
    }
};
