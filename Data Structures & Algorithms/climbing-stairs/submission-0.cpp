class Solution {
public:
    int mem[46]={0};
    int climbStairs(int n) {
        if(n==0) return 1;
        else if(n<0) return 0;
        if(mem[n]!=0) return mem[n];
        int a = climbStairs(n-1);
        int b = climbStairs(n-2);
        mem[n] = a+b;
        return mem[n];
    }
};
