class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int fresh = 0;

        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 2) q.push({i,j});
                else if(grid[i][j] == 1) fresh++;
            }
        }
        int time = 0;
        while(!q.empty() && fresh>0){
            int sz = q.size();

            for(int i=0;i<sz;i++){
                auto [r,c] = q.front();
                q.pop();

                int delrow[] = {-1,1,0,0};
                int delcol[] = {0,0,1,-1};

                for(int i=0;i<4;i++){
                    int nr = r + delrow[i];
                    int nc = c + delcol[i];

                    if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc] == 1){
                        grid[nr][nc] = 2;
                        fresh--;
                        q.push({nr,nc});
                    }
                }
            }
            time++;
        }

        if(fresh > 0) return -1;
        return time;
    }
};