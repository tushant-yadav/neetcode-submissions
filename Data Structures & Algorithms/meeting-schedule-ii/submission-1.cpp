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
    int minMeetingRooms(vector<Interval>& intervals) {
        int count = 0, n = intervals.size(), maxCnt=0;
        vector<int> startTime(n,0);
        vector<int> endTime(n,0);
        for(int i=0;i<n;i++){
            startTime[i] = intervals[i].start;
            endTime[i] = intervals[i].end;
        }
        sort(startTime.begin(),startTime.end());
        sort(endTime.begin(),endTime.end());
        int i = 0, j = 0;
        while(i<n && j<n){
            if(startTime[i]<endTime[j]){
                i++; count++;
                maxCnt = (count>maxCnt) ? count : maxCnt;
            }
            else if(startTime[i]>endTime[j]){
                j++; count--;
            }
            else{
                i++; j++;
            }
        }
        return maxCnt;
    }
};
