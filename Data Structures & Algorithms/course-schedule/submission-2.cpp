class Solution {
public:

    bool hasCycle(vector<vector<int>> &adj, vector<bool> vis, int i){
        vis[i] = 1;
        for(int j:adj[i]){
            if(!vis[j]){
                if(hasCycle(adj,vis,j)){
                    return true;
                }
            }
            else {
                return true;
            }
        }
        return false;
    }
    bool canFinish(int num, vector<vector<int>>& pre) {
        int n = pre.size();
        vector<vector<int>> adj(num);
        
        for(int i=0;i<n;i++){
            adj[pre[i][0]].push_back(pre[i][1]);
        }

        vector<bool> vis(num,0);
        for(int i=0;i<num;i++){
            if(!vis[i] && hasCycle(adj, vis, i)) return false;
        }
        return true;
    }
};
