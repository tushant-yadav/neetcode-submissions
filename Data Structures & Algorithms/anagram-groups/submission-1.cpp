class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> um;
        int n = strs.size();
        for(int i=0;i<n;i++){
            string temp_str = strs[i];
            sort(temp_str.begin(), temp_str.end());
            um[temp_str].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for(auto group:um){
            ans.push_back(group.second);
        }
        return ans;
    }
};
