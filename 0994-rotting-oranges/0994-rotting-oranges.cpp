class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> vis(grid.size(),
                                vector<int>(grid[0].size(), false));
        int time = -1;
        int freshcount = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                    vis[i][j] = true;
                }else if (grid[i][j] == 1){
                    freshcount++;
                }
            }
        }

        if(freshcount==0) return 0;

        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                if (row + 1 < n && !vis[row + 1][col] &&
                    grid[row + 1][col] == 1) {
                    q.push({row + 1, col});
                    vis[row+1][col] = true;
                    freshcount--;
                }
                if (row - 1 >= 0 && !vis[row - 1][col] &&
                    grid[row - 1][col] == 1) {
                    q.push({row - 1, col});
                    vis[row-1][col] = true;
                    freshcount--;
                }
                if (col + 1 < m && !vis[row][col + 1] &&
                    grid[row][col + 1] == 1) {
                    q.push({row, col + 1});
                    vis[row][col+1] = true;
                    freshcount--;
                }
                if (col - 1 >= 0 && !vis[row][col - 1] &&
                    grid[row][col - 1] == 1) {
                    q.push({row, col - 1});
                    vis[row][col-1] = true;
                    freshcount--;
                }
            }
            time++;
        }
        if(freshcount>0){
            return -1;
        }
        return time;
    }
};