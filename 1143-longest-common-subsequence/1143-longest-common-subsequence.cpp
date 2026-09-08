class Solution {
public:

    int helper(int idx1,int idx2,string &text1, string &text2, vector<vector<int>> &dp){

        if(idx1<0 || idx2<0){
            return 0;
        }

        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];

        if(text1[idx1] == text2[idx2]){
            return 1 + helper(idx1-1,idx2-1,text1,text2,dp);
        }

        return dp[idx1][idx2] = max(helper(idx1-1,idx2,text1,text2,dp),helper(idx1,idx2-1,text1,text2,dp));
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.size();
        int n2=text2.size();
        // vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
        vector<int> curr(n2+1,0);
        vector<int> prev(n2+1,0);

        prev[0]=0;curr[0]=0;

        // for(int i=0;i<n1;i++){
        //     dp[i][0] =0;
        // }
        // for(int i=0;i<n2;i++){
        //     dp[0][i] =0;
        // }

        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){

                if(text1[i-1] == text2[j-1]){
                    curr[j] = 1+prev[j-1];
                }else{
                    curr[j] = max(curr[j-1],prev[j]);
                }

            }
            prev = curr;
        }

        return prev[n2];

    }
};