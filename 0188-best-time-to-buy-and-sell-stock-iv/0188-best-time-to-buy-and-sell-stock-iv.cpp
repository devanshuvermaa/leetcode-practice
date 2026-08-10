class Solution {
public:

    int helper(int idx,int buy,int lim,int n, vector<int>& prices, vector<vector<vector<int>>> &dp){
        if (idx == n || lim == 0)
            return 0;
        if(dp[idx][buy][lim] != -1){
            return dp[idx][buy][lim];
        }
        if (buy) {
            return dp[idx][buy][lim] = max(-prices[idx] + helper(idx + 1, 0, lim, n, prices,dp),
                       0 + helper(idx + 1, 1, lim, n, prices,dp));
        } else {
            return dp[idx][buy][lim]= max(prices[idx] + helper(idx + 1, 1, lim - 1, n, prices,dp),
                       0 + helper(idx + 1, 0, lim, n, prices,dp));
        }

    }
    
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2,vector<int>(k+1,-1)));

        return helper(0,1,k,n,prices,dp);
    }
};