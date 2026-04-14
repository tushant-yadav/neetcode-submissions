class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // 
        while(stones.size()>1){
            sort(stones.begin(), stones.end());
            int n = stones.size();
            int a = stones[n-1], b = stones[n-2];
            stones.pop_back(); stones.pop_back();
            if(a==b) continue;
            a = abs(a-b);
            stones.push_back(a);
        }
        if(stones.size()==1) return stones[0];
        return 0;
        
    }
};
