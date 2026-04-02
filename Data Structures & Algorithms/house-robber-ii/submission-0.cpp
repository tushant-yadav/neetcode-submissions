class Solution {
public:
    int n;
    int robber(int i,int j, vector<int> nums){
        vector<int> dp(n,0);
        dp[i] = nums[i];
        if (i + 1 <= j)
            dp[i + 1] = max(nums[i], nums[i + 1]);
        
        for (int a = i + 2; a <= j; a++) {
            dp[a] = max(dp[a - 1], dp[a - 2] + nums[a]);
        }
        
        return dp[j];
    }
    int rob(vector<int>& nums) {
        n = nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        return max(robber(0,n-2,nums), robber(1,n-1,nums));
    }
};
