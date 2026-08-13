class Solution {
public:

    void helper(int idx,int target,vector<int> &nums,vector<vector<int>> &ans, vector<int> &temp,int k){
        if(target == 0 && k==0){
            ans.push_back(temp);
            return;
        }
        if(k==0){
            return;
        }
        if(idx == nums.size()){
            return;
        }
        if(nums[idx]>target){
            return;
        }

        temp.push_back(nums[idx]);
        helper(idx+1,target-nums[idx],nums,ans,temp,k-1);
        temp.pop_back();

        helper(idx+1,target,nums,ans,temp,k);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums = {1,2,3,4,5,6,7,8,9};
        vector<vector<int>> ans;
        vector<int> temp;
        helper(0,n,nums,ans,temp,k);

        return ans;
    }
};