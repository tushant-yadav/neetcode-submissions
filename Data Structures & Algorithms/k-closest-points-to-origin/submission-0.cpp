class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>/*,vector<vector<int>>,greater<vector<int>*/> pq;
        int n = points.size();
        for(int i=0;i<n;i++){
            int dist = pow(points[i][0],2) + pow(points[i][1],2);
            pq.push({dist,points[i][0],points[i][1]});
            if(pq.size()>k) pq.pop();
        }
        
        vector<vector<int>> ans;
        while(pq.size()>0){
            auto top = pq.top();
            ans.push_back({top[1], top[2]});
            pq.pop();
        }
        return ans;
        
    }
};
