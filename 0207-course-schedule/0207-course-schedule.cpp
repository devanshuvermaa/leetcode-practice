class Solution {
public:

    bool iscycle(int i, vector<bool> &vis, vector<bool> &rec, vector<vector<int>>& prerequisites){
        vis[i] = true;
        rec[i] = true;

        for(int j=0;j<prerequisites.size();j++){
            int u = prerequisites[j][1];
            int v = prerequisites[j][0];

            if(i == u){
                if(!vis[v]){
                    if(iscycle(v,vis,rec,prerequisites)){
                        return true;
                    }
                }
                else if(rec[v]){
                    return true;
                }
            }
        }
        rec[i]=false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> vis(numCourses,false);
        vector<bool> rec(numCourses,false);

        for(int i=0;i<numCourses;i++){
            if(iscycle(i,vis,rec,prerequisites)){
                return false;
            }
        }
        return true;
    }
};