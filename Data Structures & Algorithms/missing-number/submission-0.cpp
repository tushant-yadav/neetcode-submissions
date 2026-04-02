class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int num = n;
        for(int i=0;i<nums.size();i++){
            num = num^i;
            num = num^nums[i];
        }
        return num;
    }
};
