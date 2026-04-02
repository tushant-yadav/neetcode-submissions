class Solution {
public:
    bool poss[10000]={0}; 
    bool jumptolast(vector<int> &nums, int idx){
        if(poss[idx] == 1) return 0;
        int len = idx+nums[idx]; 
        if(len>=nums.size()-1) return 1;
        for(int i=len;i>idx;i--){
            if(jumptolast(nums,i)) return true;
        }
        poss[idx] = 1;
        return false;
    }
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 1;
        if(nums[0]==0) return 0;
        return jumptolast(nums,0);
    }
};
