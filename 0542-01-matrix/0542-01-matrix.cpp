class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> dist(m, vector<int>(n, -1));
        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            int delrow[] = {-1, 1, 0, 0};
            int delcol[] = {0, 0, -1, 1};

            for (int i = 0; i < 4; i++) {
                int nr = r + delrow[i];
                int nc = c + delcol[i];

                if (nr < 0 || nc < 0 || nr >= m || nc >= n)
                    continue;

                if (dist[nr][nc] == -1) {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }

        return dist;
    }
};