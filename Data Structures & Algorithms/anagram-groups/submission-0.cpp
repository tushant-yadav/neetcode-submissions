class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> um;
        for(int i=0;i<strs.size();i++){
            string s = strs[i];
            sort(s.begin(),s.end());
            if(um.find(s)!=um.end()) um[s].push_back(strs[i]);
            else
            um[s] = {strs[i]};
        }
        vector<vector<string>> ans;
        for(auto i:um){
            ans.push_back(i.second);
        }
        return ans;



        
    }
};
