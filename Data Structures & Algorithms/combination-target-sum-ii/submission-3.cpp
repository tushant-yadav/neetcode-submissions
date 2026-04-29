class Solution {
public:
    vector<vector<int>> ans;
    void helper(vector<int> & can, int i, int target, vector<int> &select){
        if(target<0) return;
        if(target==0){
            string s;
            ans.push_back(select);
            return;
        }
        if(i == can.size()) return;
        select.push_back(can[i]);
        target -= can[i];
        helper(can, i+1, target, select);
        target += can[i];
        select.pop_back();
        while(i+1<can.size() & can[i]==can[i+1]){
            i++;
        }
        helper(can,i+1,target, select);
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> select;
        helper(candidates, 0, target, select);
        return ans;
    }
};
