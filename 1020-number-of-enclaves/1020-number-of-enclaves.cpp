class Solution {
public:

    void dfs(vector<vector<int>>& grid,int r,int c, vector<vector<bool>> &vis){
        vis[r][c] = true;

        grid[r][c] = -1;

        int delrow[] = {-1,1,0,0};
        int delcol[] = {0,0,-1,1};

        for(int i=0;i<4;i++){
            int nr = r + delrow[i];
            int nc = c + delcol[i];

            if(nc>=0 && nr>=0 && nr<grid.size() && nc<grid[0].size() && grid[nr][nc] == 1){
                dfs(grid,nr,nc,vis);
            }
        }

        vis[r][c] = false;
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        int count = 0;

        for(int i=0;i<m;i++){
            if(grid[i][0] == 1){
                dfs(grid,i,0,vis);
            }
            if(grid[i][n-1] == 1){
                dfs(grid,i,n-1,vis);
            }
        }

        for(int j=0;j<n;j++){
            if(grid[0][j] == 1){
                dfs(grid,0,j,vis);
            }
            if(grid[m-1][j] == 1){
                dfs(grid,m-1,j,vis);
            }
        }

        for(int i=0;i<m;i++){
            for(int j =0;j<n;j++){
                if(grid[i][j] == 1){
                    count++;
                }
            }
        }

        return count;
    }
};