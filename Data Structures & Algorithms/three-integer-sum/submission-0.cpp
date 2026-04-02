class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        /**sort(nums.begin(),nums.end());
        vector<int> v;
        v.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(v[v.size()-1]!=nums[i]) v.push_back(nums[i]);
        }*/
        int n = nums.size();
        if(n<3) return {};
        sort(nums.begin(),nums.end());
        if(nums[0]>0) return {};
        vector<vector<int>> ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0) break;
            if(i>0 && nums[i-1]==nums[i]) continue;
            int j=i+1,k=n-1;
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum==0){
                    vector<int> temp = {nums[i],nums[j],nums[k]};
                     ans.push_back(temp);
                     while(temp[1]==nums[j] && j<k) j++;
                     while(temp[2]==nums[k] && k>j) k--;
                     }
                else if(sum<0) j++;
                else k--;
            }
        }
        return ans;
    }
};
