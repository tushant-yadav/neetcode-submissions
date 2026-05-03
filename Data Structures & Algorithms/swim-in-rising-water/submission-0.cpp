class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int gsize = grid.size();
        vector<vector<bool>> visited(gsize,vector<bool>(gsize,0));
        priority_queue<vector<int>,vector<vector<int>>, greater<vector<int>>> mp;
        mp.push({grid[0][0],0,0});
        visited[0][0] = 1;
        int time=0;
        vector<vector<int>> dir = {
            {0,1},
            {0,-1},
            {1,0},
            {-1,0}
        };
        while(!mp.empty()){
            vector<int> cur = mp.top();
            mp.pop();
            time = max(time,cur[0]);
            if(cur[1] == gsize-1 && cur[2] == gsize-1) return time;
            for(auto d:dir){
                int nr = cur[1]+d[0];
                int nc = cur[2]+d[1];
                if(nr>=0 && nr<gsize && nc>=0 && nc<gsize && !visited[nr][nc]){
                    visited[nr][nc]=1;
                    mp.push({grid[nr][nc],nr,nc});
                }
            }
        }
        return time;
    }
};
