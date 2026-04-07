class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int res=INT_MIN;
        int cmax = 1, cmin=1;
        for(int num:nums){
            if(num==0){
                cmax = 1; cmin=1;
            }
            int temp = cmax*num;
            //cout<<cmax*n<<":"<<cmin*n<<":"<<num<<"{}"<<temp<<endl;

            cmax = max(max(temp, cmin*num),num);
            cmin = min(min(temp, cmin*num),num);
            //cout<<cmax<<":"<<cmin<<":"<<num<<"{}"<<temp<<endl;

            if(res<cmax) res = cmax;
        }
        return res;
        
    }
};
