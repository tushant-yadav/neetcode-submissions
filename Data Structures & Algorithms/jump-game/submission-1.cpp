class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int cur_reach = 0;
        for(int i=0;i<n;i++){
            if(i>cur_reach) return false;
            cur_reach = max(cur_reach,i+nums[i]);
        }
        return true;
    }
};
