class Solution {
public:
    int helper(int r, int c, int m, int n, vector<vector<int>>& dp, vector<vector<int>>& grid) {
        if (r >= m || c >= n || grid[r][c]==1) {
            return 0;
        }

        if (r == m - 1 && c == n - 1) {
            return 1;
        }

        if (dp[r][c] != -1) {
            return dp[r][c];
        }

        int movedown = helper(r + 1, c, m, n, dp,grid);
        int moveright = helper(r, c + 1, m, n, dp, grid);

        return dp[r][c] = movedown + moveright;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n,-1));
        return helper(0,0,m,n,dp,obstacleGrid);
    }
};