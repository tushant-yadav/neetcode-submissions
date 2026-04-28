class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        n++;
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<times.size();i++){
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }

        vector<int> qtime(n,INT_MAX);
        priority_queue<pair<int,int>> q;
        q.push({0,k});
        int max_time = INT_MIN;
        while(!q.empty()){
           auto [time, node] = q.top();
            q.pop();
            qtime[node] = min(qtime[node], time);
            for(auto p:adj[node]){
                int next_time = time+p.second;
                if(next_time < qtime[p.first]){
                    q.push({next_time, p.first});
                }
            }
        }
        for(int i=1;i<n;i++){
            cout<<qtime[i]<<":";
            max_time = max(max_time, qtime[i]);
        }
        return max_time==INT_MAX?-1:max_time;
    }
};
