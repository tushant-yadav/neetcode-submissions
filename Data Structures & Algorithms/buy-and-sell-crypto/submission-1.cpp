class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0; int minimum = prices[0], maximum = INT_MIN;
        int n = prices.size();
        for(int i=0;i<n;i++){
            if(prices[i]<minimum){
                minimum = prices[i];
                maximum = INT_MIN;
            }
            if(prices[i]>maximum){
                maximum = prices[i];
                profit = max(profit,maximum - minimum);
            }
        }
        return profit;
    }
};
