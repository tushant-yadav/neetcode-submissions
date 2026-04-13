class Solution {
public:
    vector<vector<int>> ans;
    void helper(vector<int>& nums, int target, vector<int> current, int i){
        if(0>target) return;
        if(0==target) ans.push_back(current);
        if(i>=nums.size()) return;

        for(int j=i;j<nums.size();j++){
            target -= nums[j];
            if(target<0) break;
            current.push_back(nums[j]);
            helper(nums,target,current,j);
            target+= nums[j];
            current.pop_back();
        }

        return;
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        helper(nums, target, {},0);
        return ans;
        
    }
};
