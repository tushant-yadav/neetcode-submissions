class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> visited(n,0);
        queue<pair<int,int>> q;
        q.push({0,-1});
        while(!q.empty()){
            int parent, num;
            pair<int,int> p = q.front();
            num=p.first; 
            parent=p.second;
            q.pop();
            if(visited[num]) return 0;
            visited[num] = 1;
            for(int i=0;i<adj[num].size();i++){
                if(adj[num][i]!=parent)
                    q.push({adj[num][i],num});
            }
        }
        for(int i=0;i<n;i++){
            if(!visited[i]) return 0;
        }
        return 1;
    }
};
