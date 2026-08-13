class Solution {
public:

    void helper(int idx,vector<int>& nums,int n,vector<int> &temp,vector<vector<int>> &ans){
        if(idx == n){
            return;
        }

        for(int i= idx;i<n;i++){
            if(i>idx && nums[i] == nums[i-1]){
                continue;
            }
            temp.push_back(nums[i]);
            ans.push_back(temp);
            helper(i+1,nums,n,temp,ans);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans={{}};
        vector<int> temp;
        int n = nums.size();
        helper(0,nums,n,temp,ans);
        return ans;
    }
};