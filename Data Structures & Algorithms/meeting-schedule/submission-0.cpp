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

class Solution {
public:
    static bool comp(Interval i1, Interval i2){
        return i1.end<i2.end;
    }
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(),comp);
        int n = intervals.size();
        for(int i=0;i<n-1;i++){
            if(intervals[i].end>intervals[i+1].start)
                return false;
        }
        return true;
    }
};
