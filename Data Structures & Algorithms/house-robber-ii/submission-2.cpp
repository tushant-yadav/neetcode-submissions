class Solution {
    vector<int> mem;
public:
    int solve(vector<int> &nums, int i, int e){
        if(i>e) return 0;
        if(mem[i]==-1)
            mem[i] = max(solve(nums,i+1,e), solve(nums,i+2,e)+nums[i]);
        return mem[i];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if(n==0) return 0;
        mem.assign(n, -1);
        int res = solve(nums, 0, n-2);
        mem.assign(n,-1);
        return max(res, solve(nums,1,n-1));
    }
};
