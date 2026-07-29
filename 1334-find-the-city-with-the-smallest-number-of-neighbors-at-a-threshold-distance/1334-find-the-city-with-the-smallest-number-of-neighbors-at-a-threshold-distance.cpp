class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> grid(n,vector<int>(n,1e9));

        for(int i=0;i<n;i++){
            grid[i][i] = 0;
        }

        for(auto &it:edges){
            grid[it[0]][it[1]] = it[2];
            grid[it[1]][it[0]] = it[2];
        }

        for(int k=0; k<n; k++){
            for(int i =0; i<n; i++){
                for(int j=0; j<n; j++){
                    
                    if(grid[i][k]!=1e9 && grid[k][j]!=1e9){
                        if(grid[i][j] > grid[i][k] + grid[k][j]){
                            grid[i][j] = grid[i][k] + grid[k][j];
                        }
                    }
                }
            }
        }

        int min_count = n;
        int cityno = 0;

        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(grid[i][j] <= distanceThreshold){
                    count++;
                }
            }
            if(count<=min_count){
                min_count = count;
                cityno = i;
            }
        }

        return cityno;
    }
};