class Solution {
public:
    bool iscycle(int i, vector<bool>& vis, vector<bool>& rec,
                 vector<vector<int>>& prerequisites) {
        vis[i] = true;
        rec[i] = true;

        for (int j = 0; j < prerequisites.size(); j++) {
            int u = prerequisites[j][1];
            int v = prerequisites[j][0];

            if (i == u) {
                if (!vis[v]) {
                    if (iscycle(v, vis, rec, prerequisites)) {
                        return true;
                    }
                } else if (rec[v]) {
                    return true;
                }
            }
        }
        rec[i] = false;
        return false;
    }

    void toposort(int src, vector<bool> &vis, stack<int> &s, vector<vector<int>>& prerequisites){
        vis[src] = true;

        for (int j = 0; j < prerequisites.size(); j++) {
            int u = prerequisites[j][1];
            int v = prerequisites[j][0];

            if (src == u) {
                if (!vis[v]) {
                    toposort(v,vis,s,prerequisites);
                }
            }
        }

        s.push(src);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> vis(numCourses,false);
        vector<bool> rec(numCourses,false);
        vector<int> ans;

        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(iscycle(i,vis,rec,prerequisites)){
                    return ans;
                }
            }
        }
        
        vector<bool> vis2(numCourses,false);
        stack<int> s;
        
        for(int i=0;i<numCourses;i++){
            if(!vis2[i]){
                toposort(i,vis2,s,prerequisites);
            }
        }
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};