class Solution {
public:

    void dfs(int row, int col, int n, int m, vector<vector<char>>& grid, vector<vector<bool>> &vis){
        vis[row][col] = true;

        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};

        for(int i=0;i<4;i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow < n && nrow >=0 && ncol < m && ncol >=0 && !vis[nrow][ncol] && grid[nrow][ncol] == '1'){
                dfs(nrow, ncol, n, m, grid, vis);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m,false));
        int count = 0;

        for(int i=0 ;i<n; i++){
            for(int j=0; j<m;j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    dfs(i,j,n,m,grid,vis);
                    count++;
                }
            }
        }
        return count;
    }
};