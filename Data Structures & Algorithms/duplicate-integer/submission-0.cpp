class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,bool> m;
        int n = nums.size();
        while(n--){
            cout<<nums[n]<<" ";
            if(m[nums[n]]) return 1;
            m[nums[n]]=1;
            
        }
        return 0;
        
    }
};
