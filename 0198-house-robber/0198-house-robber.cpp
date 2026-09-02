class Solution {
public:
    int helper(int n, int picked,vector<int>& nums, vector<vector<int>> &dp) {
        if (n < 0)
            return 0;

        if(dp[n][picked] != -1){
            return dp[n][picked];
        }

        int notpick = helper(n-1,0,nums,dp);
        int pick = -1e9;

        if (picked == 0) {
            pick = nums[n] + helper(n - 1, 1,nums,dp);
        }
        return dp[n][picked] = max(pick,notpick);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return helper(n-1,0,nums,dp);
    }
};