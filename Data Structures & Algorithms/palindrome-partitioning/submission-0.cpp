class Solution {
public:
    unordered_map<string,bool> pm;
    vector<vector<string>> ans;

    bool isPali(string s){
        if(pm.find(s)==pm.end()){
            bool flag = 1;
            int n = s.size();
            for(int i=0;i<n;i++){
                if(s[i]!=s[n-i-1]) {
                    flag = 0;
                    break;
                }
            }
            pm[s] = flag;
        }
        return pm[s];
    }

    void helper(string &s, int start, vector<string> &v){
        if(start >= s.size()){
            ans.push_back(v);
        }

        for(int i=start;i<s.size();i++){
            string temp = s.substr(start, i-start+1);
            if(isPali(temp)){
                v.push_back(temp);
                helper(s,i+1,v);
                v.pop_back();
            }
        }

        return;
    }
    vector<vector<string>> partition(string s) {
        vector<string> v;
        helper(s,0,v);
        return ans;
       
    }
};
