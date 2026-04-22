class MedianFinder {
public:
    priority_queue<int> dec_pq;
    priority_queue<int,vector<int>,greater<int>> inc_pq;
    MedianFinder() {

        
    }
    
    void addNum(int num) {
        dec_pq.push(num);

        inc_pq.push(dec_pq.top());
        dec_pq.pop();

        if (dec_pq.size() < inc_pq.size()) {
            dec_pq.push(inc_pq.top());
            inc_pq.pop();
        }
    }
    
    double findMedian() {
        if (dec_pq.size() > inc_pq.size()) {
            return (double)dec_pq.top();
        }
        return (dec_pq.top()+inc_pq.top())/2.0;
    }
};
