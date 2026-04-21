class Solution {
public:
    static bool comp(vector<int> a, vector<int> b){
        return a[1]<b[1];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n==0) return {};
        if(n==1) return intervals;
        sort(intervals.begin(), intervals.end(),comp);
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for(int i=1;i<n;i++){
            int m = res.size();
            if(m>0 && res[m-1][1]>=intervals[i][0]){
                intervals[i][0] = min(res[m-1][0],intervals[i][0]);
                intervals[i][1] = max(res[m-1][1],intervals[i][1]);
                res.pop_back();
                i--;
            }
            else{
                res.push_back(intervals[i]);
            }

        }
        return res;
        
    }
};
