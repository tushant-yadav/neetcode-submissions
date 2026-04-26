class Solution {
public:
    vector<vector<int>> ans;
    void helper(vector<int>& nums, vector<int> &current, int i){
        if(i>=nums.size()){
            if(current.size()!=0)
                ans.push_back(current);
            return;
        }

        current.push_back(nums[i]);
        helper(nums, current, i+1);
        current.pop_back();
        helper(nums, current, i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        ans.push_back({});
        vector<int> current;
        helper(nums, current, 0);
        return ans;
    }
};
