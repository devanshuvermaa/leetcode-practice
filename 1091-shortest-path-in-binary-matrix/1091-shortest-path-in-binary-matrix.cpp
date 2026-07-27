class Solution {
public:

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if(grid[0][0] == 1 || grid[n-1][n-1] == 1){
            return -1;
        }

        if(n==1) return 1;

        queue<pair<int,pair<int,int>>> q;
        q.push({1,{0,0}});
        grid[0][0] = 1; //mark as visited

        int delrow[] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int delcol[] = {-1, 0, 1, 1, 1, 0, -1, -1};

        while(!q.empty()){
            int dist = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;
            q.pop();

            for(int i=0; i<8; i++){
                int nr = r+delrow[i];
                int nc = c+delcol[i];

                if(nr >=0 && nr < n && nc>=0 && nc<n && grid[nr][nc] == 0){
                    if(nr == n-1 && nc == n-1){
                        return dist +1 ;
                    }
                    q.push({dist+1,{nr,nc}});
                    grid[nr][nc] = 1;
                }
            }
        }
        return -1;
    }
};