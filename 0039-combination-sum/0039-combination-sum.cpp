class Solution {
public:

    void helper(int idx,vector<int>& candidates, int target,vector<vector<int>> &ans,vector<int> &temp){
        if(target == 0){
            ans.push_back(temp);
            return;
        }

        for(int i=idx;i<candidates.size();i++){
            int curr = candidates[i];
            if(curr <= target){
                temp.push_back(curr);
                helper(i,candidates,target-curr,ans,temp);
                temp.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(0,candidates,target,ans,temp);
        return ans;
    }
};