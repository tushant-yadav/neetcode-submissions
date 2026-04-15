class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();

        for(int i=0;i<n;i++){
           // if(nums[i]<0) nums[i]*=-1;
           int abs_val = abs(nums[i]);
            if(nums[abs_val]<0) return abs_val;
            nums[abs(nums[i])]*=-1;
        }
        return 0;
    }
};
