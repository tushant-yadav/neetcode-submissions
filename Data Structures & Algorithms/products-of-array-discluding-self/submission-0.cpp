class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,1);
       
        for(int i=1;i<n;i++){
            ans[i] = nums[i-1]*ans[i-1];
            //cout<<ans[i]<<":"<<nums[i-1]<<"*"<<ans[i-1]<<":"<<i<<endl;
        }
        int pro = 1;
        for(int i = n-1;i>0;i--){
            pro*=nums[i];
            ans[i-1] = pro*ans[i-1];
            //cout<<ans[i-1]<<":"<<nums[i-1]<<"*"<<ans[i-1]<<":"<<i<<endl;
        }
        return ans;
        
    }
};
