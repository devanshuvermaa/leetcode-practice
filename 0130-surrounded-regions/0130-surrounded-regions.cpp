class Solution {
public:

    void dfs(vector<vector<char>>& board,int r,int c, vector<vector<bool>> &vis){
        vis[r][c] = true;

        board[r][c] = '#';

        int delrow[] = {-1,1,0,0};
        int delcol[] = {0,0,-1,1};

        int m = board.size();
        int n = board[0].size();

        for(int i = 0;i<4;i++){
            int nr = r + delrow[i];
            int nc = c + delcol[i];

            if(nr>=0 && nc>=0 && nr<m && nc<n && !vis[nr][nc] && board[nr][nc] == 'O'){
                dfs(board,nr,nc,vis);
            }
        }
        vis[r][c] = false;
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));

        for(int i=0;i<m;i++){
            if(board[i][0] == 'O'){
                dfs(board,i,0,vis);
            }
            if(board[i][n-1] == 'O'){
                dfs(board,i,n-1,vis);
            }
        }

        for(int j=0;j<n;j++){
            if(board[0][j] == 'O'){
                dfs(board,0,j,vis);
            }
            if(board[m-1][j] == 'O'){
                dfs(board,m-1,j,vis);
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                if(board[i][j] == '#'){
                    board[i][j] = 'O';
                }
            }
        }
        
    }
};