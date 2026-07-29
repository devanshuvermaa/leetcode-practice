class Solution {
public:

    void dfs(int src,vector<bool> &vis,vector<vector<int>>& adj){
        vis[src] = true;

        for(auto nextnode : adj[src]){
            if(!vis[nextnode]){
                    dfs(nextnode,vis,adj);
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1){
            return -1;
        }
        vector<vector<int>> adj(n);
        for(auto it : connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int count=0;
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,vis,adj);
                count++;
            }
        }
        return count-1;
    }
};