class Solution {
public:
    vector<vector<int>> dp{20,vector<int>(20,0)};
    int findTargetSumWays(vector<int>& nums, int target, int i = 0, int sum = 0) {
        int n = nums.size();
        if(i==n){
            if(sum == target){
                return 1;
            }
            return 0;
        }

        return findTargetSumWays(nums,target,i+1,sum+nums[i]) + findTargetSumWays(nums,target,i+1,sum-nums[i]); 
    }
};
