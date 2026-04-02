class Solution {
public:
    int findMin(vector<int> &nums) {
        int i = 0, j = nums.size()-1;
        while(i<j){
            int k =  (j+i)/2;
            if(nums[k]>nums[j]){
                i = k+1;
            }
            else{
                j=k;
            }
        }
        return nums[i];
        
    }
};
