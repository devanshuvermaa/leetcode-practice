class Solution {
public:
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m =heights[0].size();

        vector<vector<int>> effort(n,vector<int>(m,INT_MAX));
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        int delrow[]={-1,0,1,0};
        int delcol[] = {0,1,0,-1};

        pq.push({0,{0,0}});

        while(!pq.empty()){
            int curreffort = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();

            if(r==n-1 && c==m-1){
                return curreffort;
            }

            for(int i=0;i<4;i++){
                int nr = r+delrow[i];
                int nc = c+delcol[i];

                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    int nexteffort = max(curreffort,abs(heights[nr][nc]-heights[r][c]));

                    if(nexteffort < effort[nr][nc]){
                        effort[nr][nc] = nexteffort;
                        pq.push({nexteffort,{nr,nc}});
                    }
                }
            }
        }
        return 0;
    }
};