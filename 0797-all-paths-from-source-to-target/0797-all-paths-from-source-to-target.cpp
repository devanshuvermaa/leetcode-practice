class Solution {
public:
    void dfs(int src,vector<vector<int>>& adj, vector<int> &temp, vector<vector<int>> &ans, int target){

        temp.push_back(src);
        if(src == target){
            ans.push_back(temp);
            temp.pop_back();
            return;
        }
        for(int n:adj[src]){
            dfs(n,adj,temp,ans,target);
        }
        temp.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int V = graph.size();
        int target = V-1;
        vector<vector<int>> ans;
        vector<int> temp;
        dfs(0,graph,temp,ans,target);
        return ans;
    }
};