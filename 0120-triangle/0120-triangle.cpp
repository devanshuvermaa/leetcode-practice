class Solution {
public:

    int helper(int n,int level, int i, vector<vector<int>>& triangle, vector<vector<int>> &dp){
        if(n==level){
            return 0;
        }
        
        if(dp[level][i]!=1e7){
            return dp[level][i];
        }

        int samei = helper(n, level+1, i,triangle,dp);
        int nexti = helper(n, level+1, i+1,triangle,dp);

        return dp[level][i] = min(samei,nexti) + triangle[level][i];
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[0].size();
        vector<vector<int>> dp(n,vector<int>(n,1e7));
        return helper(n,0,0,triangle,dp);
    }
};