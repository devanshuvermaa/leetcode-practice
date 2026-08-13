class Solution {
public:
    void helper(int idx,vector<int>& candidates, int target,vector<vector<int>> &ans,vector<int> &temp){
        if(target == 0){
            ans.push_back(temp);
            return;
        }

        for(int i=idx;i<candidates.size();i++){
            if(i>idx && candidates[i] == candidates[i-1]){
                continue;
            }
            int curr = candidates[i];
            if(curr > target){
                break;
            }
            temp.push_back(curr);
            helper(i+1,candidates,target-curr,ans,temp);
            temp.pop_back();
            
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(),candidates.end());
        helper(0,candidates,target,ans,temp);
        return ans;
    }
};