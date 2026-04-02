class Solution {
public:
    void helper(vector<int>& nums,vector<vector<int>>& ans,vector<int> v, int idx,int target){
        if(idx>=nums.size()) return;
        if(0==target){
            ans.push_back(v);
            return;
        }
        //helper(nums,ans,v,idx+1,target);
        for(int i=idx;i<nums.size();i++){
            target-=nums[i];
            if(0>target) break;
            v.push_back(nums[i]);
            helper(nums,ans,v,i,target);
            target+=nums[i];
            v.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<vector<int>> v;
        helper(nums, ans,{},0,target);
        //for(auto i:ans){
        //    v.push_back(i);
        //}
        return ans;
    }
};