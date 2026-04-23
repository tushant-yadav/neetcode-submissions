class Solution {
public:

    unordered_map<int,bool> cycleMembers;
    bool flag = false;
    void dfs(vector<vector<int>> & node, vector<bool> &visited, int parent, vector<int> tracedPath, int currentIdx){
        if(flag) return;
        visited[currentIdx]=1;
        tracedPath.push_back(currentIdx);

        for(int i:node[currentIdx]){
            if(i==parent) continue;

            if(visited[i]){ //cycle detected
                int m = tracedPath.size();
                for(int j = m-1;j>=0;j--){
                    cycleMembers[tracedPath[j]] = 1;
                    if(tracedPath[j] == i){
                        flag = 1;
                        return; //cycle complete
                    }
                }
            }
            dfs(node, visited, currentIdx, tracedPath, i);
            if(flag) return;
        }
        //visited[currentIdx] = 0;
        tracedPath.pop_back();

    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> um(n+1);
        for(int i=0;i<n;i++){
            um[edges[i][0]].push_back(edges[i][1]);
            um[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<bool> visited(n+1,0);        
        for(int i=1;i<=n;i++){    
            if(!visited[i]) dfs(um, visited, -1,{},1);
        }
    
        for(int i = n-1;i>=0;i--){
            if(cycleMembers[edges[i][0]] && cycleMembers[edges[i][1]]){
                return {edges[i][0] , edges[i][1]};
            }
        }
        return {};
    }
};
