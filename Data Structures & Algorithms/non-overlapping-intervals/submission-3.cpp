class Solution {
public:

    static bool comp(vector<int> a, vector<int> b){
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        int count = 0, n = intervals.size();
        if(n==0 || n==1) return 0;
        int lastEnd = intervals[0][1];
        for(int i=1;i<n;i++){
            if(intervals[i][0]<lastEnd){
                count++;
                lastEnd = min(intervals[i][1], lastEnd);
            }
            else{
                lastEnd = intervals[i][1];
            }
        }
        return count;
    }
};
