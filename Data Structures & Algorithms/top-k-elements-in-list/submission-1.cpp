class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> um;
        for(auto num:nums){
            um[num] = um[num]+1;
        }
        vector<vector<int>> freq(n+1);
        for(auto num:um){
            freq[num.second].push_back(num.first);
        }

        vector<int> res;
        for(int i=freq.size()-1;i>0;i--){
            for(auto num:freq[i]){
                res.push_back(num);
                if(res.size()==k){
                    return res;
                }
            }
        }
        return res;

    }
};
