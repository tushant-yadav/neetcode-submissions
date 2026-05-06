class Solution {
public:
    vector<vector<string>> ans;

    bool isPali(const string& s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }

    void helper(string &s, int start, vector<string> &v){
        if(start >= s.size()){
            ans.push_back(v);
        }

        for(int i=start;i<s.size();i++){
            if(isPali(s, start, i)){
                string temp = s.substr(start, i-start+1);
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
