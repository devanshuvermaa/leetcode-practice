class Solution {
public:
    void helper(int i,vector<int>& nums,vector<vector<int>> &ans){
        if(i == nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int idx = i;idx<nums.size();idx++){
            swap(nums[idx],nums[i]);
            helper(i+1,nums,ans);
            swap(nums[idx],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        helper(0,nums,ans);
        return ans;
    }
};