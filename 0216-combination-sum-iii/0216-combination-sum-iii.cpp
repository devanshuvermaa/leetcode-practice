class Solution {
public:

    void helper(int num,int target,vector<vector<int>> &ans, vector<int> &temp,int k){
        if(target == 0 && k==0){
            ans.push_back(temp);
            return;
        }
        if(k==0 || num>9 || num>target){
            return;
        }
        
        temp.push_back(num);
        helper(num+1,target-num,ans,temp,k-1);
        temp.pop_back();

        helper(num+1,target,ans,temp,k);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(1,n,ans,temp,k);

        return ans;
    }
};