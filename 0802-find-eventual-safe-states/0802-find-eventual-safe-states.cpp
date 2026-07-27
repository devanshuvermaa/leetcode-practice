class Solution {
public:

    bool iscycle(int src, vector<bool> &vis, vector<bool> &recpath, vector<vector<int>>& graph){
        vis[src] = true;
        recpath[src] = true;

        for(int e : graph[src]){
            if(!vis[e]){
                if(iscycle(e,vis,recpath,graph)){
                    return true;
                }
            }
            else if(recpath[e]){
                return true;
            }
        } 
        recpath[src] = false;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<bool> recpath(V,false);
        vector<int> ans;
        for(int i=0 ; i<V ;i++){
            vector<bool> vis(V,false);
            if(!iscycle(i,vis,recpath,graph)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};