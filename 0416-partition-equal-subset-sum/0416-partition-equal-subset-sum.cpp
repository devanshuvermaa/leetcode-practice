class Solution {
public:

    bool helper(int ind, int target, vector<int>& nums, vector<vector<int>> &dp){
        if(target == 0){
            return true;
        }

        if(ind == 0){
            return nums[0] == target;
        }

        if(dp[ind][target]!=-1){
            return dp[ind][target]==1;
        }

        bool skip = helper(ind-1,target,nums,dp);
        bool pick = false;
        if(nums[ind] <= target){
            pick = helper(ind-1, target-nums[ind], nums, dp);
        }

        dp[ind][target] = (skip || pick)?1:0;

        return skip || pick;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total = accumulate(nums.begin(),nums.end(),0);
        int target = total/2;

        if(total % 2 != 0){
            return false;
        }

        vector<vector<int>> dp(n, vector<int>(target+1,-1));

        return helper(n-1, target, nums, dp);
    }
};