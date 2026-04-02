class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        int j = 0;
        for(int i =0;i<n;i++){
            if('a' <= s[i] && s[i]<='z' || '0'<=s[i] && '9'>=s[i] ) {
                s[j]=s[i];
                j++;
            }
            else if('A' <= s[i] && s[i]<='Z'){
                s[j] = 'a' + s[i]- 'A';
                j++;
            }

        }
        for(int i=0;i<j/2;i++){
            if(s[i]!=s[j-i-1]){
                return 0;
            } 
        }
        return 1;
    }
};
