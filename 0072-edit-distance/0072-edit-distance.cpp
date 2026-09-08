class Solution {
public:

    int helper(int i,int j,string &s, string &t, vector<vector<int>> &dp){
        if(i<0) return j+1;
        if(j<0) return i+1;

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(s[i] == t[j]){
            return helper(i-1,j-1,s,t,dp);
        }

        int insert = 1 + helper(i,j-1,s,t,dp);
        int dele = 1 + helper(i-1,j,s,t,dp);
        int replace = 1 + helper(i-1,j-1,s,t,dp);

        return dp[i][j] = min(insert,min(dele,replace));
    }

    int minDistance(string word1, string word2) {
        int n1 = word1.length();
        int n2 = word2.length();
        vector<vector<int>> dp(n1, vector<int> (n2,-1));
        return helper(n1-1,n2-1,word1,word2,dp);
    }
};