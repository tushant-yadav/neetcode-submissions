class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }
        int visited=0;
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0) 
                q.push(i);
        }
        while(!q.empty()){
            int i = q.front();
            q.pop();
            visited++;
            for(int j = 0;j<adj[i].size();j++){
                indegree[adj[i][j]]--;
                if(indegree[adj[i][j]]==0)
                    q.push(adj[i][j]);
            }
        }
        return visited==numCourses?1:0;  
    }
};
