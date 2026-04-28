class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Use a min-heap: priority_queue<Type, Container, Comparison>
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<vector<pair<int, int>>> adj(n + 1);
        
        for (auto& t : times) {
            adj[t[0]].push_back({t[1], t[2]});
        }

        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            // Optimization: Skip if we found a better path already
            if (d > dist[u]) continue;

            for (auto& edge : adj[u]) {
                int v = edge.first;
                int weight = edge.second;
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        int max_time = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) return -1;
            max_time = max(max_time, dist[i]);
        }

        return max_time;
    }
};