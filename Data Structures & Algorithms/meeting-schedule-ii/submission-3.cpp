/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

static bool comp(Interval a, Interval b){
    return a.start<b.start;
}
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size();
        if(n==0) return 0;
        priority_queue<int,vector<int>,greater<int>> pq;
        sort(intervals.begin(),intervals.end(), comp);
        int ans = 0, current = 0;
        for(int i=0;i<n;i++){
            while(!pq.empty() && pq.top()<=intervals[i].start){
                cout<<pq.top()<<":"<<pq.size()<<" ";
                pq.pop();
            }
            pq.push(intervals[i].end);
            ans = ans<pq.size()?pq.size():ans;
        }
        return ans;
        
    }
};
