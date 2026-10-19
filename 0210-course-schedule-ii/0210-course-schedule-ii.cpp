class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;
        vector<int> in(V, 0);
        vector<vector<int>> adj(V);
        for (auto p : prerequisites) {
            adj[p[1]].push_back(p[0]);
        }

        for (auto p : prerequisites) {
            in[p[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (in[i] == 0)
                q.push(i);
        }

        vector<int> ans;
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            ans.push_back(node);

            for (int next:adj[node]){
                in[next]--;
                if(in[next] == 0){
                    q.push(next);
                }
            }
        }
        for (int i = 0; i < V; i++) {
            if (in[i] > 0)
                return {};
        }
        return ans;
    }
};