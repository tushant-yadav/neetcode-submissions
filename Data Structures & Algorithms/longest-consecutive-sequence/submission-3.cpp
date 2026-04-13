class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,bool> um;
        for(int num:nums)
            um[num] = 1;

        int count = 0, max_count = 0;
        for(int num:nums){
            // int temp = num;
            // while(um[temp]==1){
            //     count++;
            //     temp--;
            //     // cout<<temp<<endl;
            // }
            int temp = num;
            while(um[temp]==1){
                count++;
                temp++;
            }
            max_count = max(count, max_count);
            count = 0;
        }
        return max_count;

    }
};
