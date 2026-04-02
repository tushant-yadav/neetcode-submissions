class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int currentmin = INT_MAX, currentmax = INT_MIN, profit = 0;
        for(int i=0;i<prices.size();i++){
            if(currentmin>prices[i]){
                currentmin = prices[i];
                currentmax = INT_MIN;
            }
            if(currentmax<prices[i]){
                currentmax = prices[i];
            }
            profit = max(profit, currentmax-currentmin);
        }
        return profit;
        
    }
};
