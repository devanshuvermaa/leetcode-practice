class Solution {
public:
    int helper(int idx1, int idx2, string& text1, string& text2,
               vector<vector<int>>& dp) {

        // if (idx2 == 0) {
        //     if (text1[idx1] == text2[idx2]) {

        //         return 1;
        //     }
        //     return 0; 
        // }
        if(idx2<0) return 1;
        if(idx1<0) return 0;

        if (dp[idx1][idx2] != -1)
            return dp[idx1][idx2];

        if (text1[idx1] == text2[idx2]) {
            return dp[idx1][idx2] = helper(idx1-1,idx2,text1,text2,dp) + helper(idx1 - 1, idx2 - 1, text1, text2, dp);
        }
        
        return dp[idx1][idx2] = helper(idx1-1,idx2,text1,text2,dp);
    }

    int numDistinct(string s, string t) {
        int n1=s.size();
        int n2=t.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));

        return helper(n1-1,n2-1,s,t,dp);
    }
};