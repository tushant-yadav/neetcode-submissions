class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        vector<int> present(256,-1);
        int maxlen=0;
        int last = 0;
        for(int i=0;i<n;i++){
            if(present[s[i]]!=-1){
                last = max(last, present[s[i]] + 1);
            }
            present[s[i]] = i;
            maxlen = max(maxlen,i -last+1);
        }
        return maxlen;
    }
};
