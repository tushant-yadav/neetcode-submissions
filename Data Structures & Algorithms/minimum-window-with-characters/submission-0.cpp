class Solution {
public:
    string minWindow(string s, string t) {
        if(t=="" || s.size()<t.size()) return "";

        unordered_map<char,int> mapT,mapS;
        for(char c:t){
            mapT[c]++;
        }
        int l=0, reslen = INT_MAX;
        int have = 0, need = mapT.size();
        pair<int,int> res{-1,-1};
        for(int r=0;r<s.size();r++){
            char c = s[r];
            mapS[c]++;
            if(mapT.find(c)!=mapT.end() && mapS[c]==mapT[c]){
                have++;
            }
            while(have==need){
                if(reslen > r-l+1){
                    reslen = r-l+1;
                    res = {l,r};
                }
                
                mapS[s[l]]--;
                if(mapT.find(c)!=mapT.end() && mapS[s[l]]<mapT[s[l]]) 
                    have--;
                l++;                
            }
        }
        return reslen==INT_MAX?"":s.substr(res.first,reslen);
    }
};
