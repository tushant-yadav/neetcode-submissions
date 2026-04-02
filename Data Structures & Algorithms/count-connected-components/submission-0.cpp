class Solution {
public:
    void dfs(vector<vector<int>>& edges, vector<bool> &visited, int i){
        visited[i] = 1;
        for(int j=0;j<edges[i].size();j++){
            if(visited[edges[i][j]]==0)
                dfs(edges, visited, edges[i][j]);
        }
        return;
    }
    int countComponents(int n, vector<vector<int>>& edge) {
        vector<vector<int>> edges(n);
        int m = edge.size();
        for(int i=0;i<m;i++){
            edges[edge[i][0]].push_back(edge[i][1]);
            edges[edge[i][1]].push_back(edge[i][0]);
        }
        vector<bool> visited(n,0); 
        int connected=0;
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                dfs(edges,visited,i);
                connected++;
            }
        }
        return connected;
    }
};
