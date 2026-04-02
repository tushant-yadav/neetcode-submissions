class Solution {
public:
    unordered_map<int, bool> seen;
    bool isHappy(int n) {
        if(n == 1) return 1;
        if(seen[n] == 1) return 0;
        seen[n]=1;
        int newnum = 0 ; 

        while(n!=0){
            int i = n%10; n = n/10;
            newnum += i*i;
        }
        return isHappy(newnum);
        
    }
};
