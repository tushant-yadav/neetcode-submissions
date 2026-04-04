class Solution {
public:
    int climbStairs(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        int one=1, two = 1; int temp = 0;

        for(int i=n-2;i>=0;i--){
            temp = one+two;
            two = one;
            one = temp;
        }
        return temp;

        
    }
};
