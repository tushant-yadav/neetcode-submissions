class Solution {
public:

    bool hasCycle(vector<vector<int>> &adj, vector<bool> &vis, int i, int parent){
        vis[i]=1;
        for(int j:adj[i]){
            if (!vis[j]) {
                if (!hasCycle(adj, vis, j, i)) return false;
            } 
            else if (j != parent) {
                return false;
            }
        }
        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<bool> visited(n,0);

        if(!hasCycle(adj, visited, 0,-1)) return false;
        for(bool v:visited) {
            if(!v) return false;
        }
        return true;
    }
};
