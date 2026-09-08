class Solution {
public:
    int helper(int ind, int target, vector<int>& nums,
               vector<vector<int>>& dp) {

        if (ind < 0) {
            if (target == 0) {
                return 1;
            }
            return 0;
        }

        if (dp[ind][target] != -1) {
            return dp[ind][target];
        }

        int skip = helper(ind - 1, target, nums, dp);
        int pick = 0;
        if (nums[ind] <= target) {
            pick = helper(ind , target - nums[ind], nums, dp);
        }

        return dp[ind][target] = skip + pick;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));

        return helper(n-1,amount,coins,dp);
    }
};