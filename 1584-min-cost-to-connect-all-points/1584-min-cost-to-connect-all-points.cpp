class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int V = points.size();
        vector<bool> vis(V,false);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        int total_cost = 0;

        pq.push({0,0}); //cost node

        while(!pq.empty()){
            int currnode = pq.top().second;
            int cost = pq.top().first;
            pq.pop();
            if(vis[currnode]) continue;

            vis[currnode] = true;
            total_cost += cost;

            for(int nextnode=0;nextnode<V;nextnode++){
                if(!vis[nextnode]){
                    int x1 = points[currnode][0];
                    int y1 = points[currnode][1];
                    int x2 = points[nextnode][0];
                    int y2 = points[nextnode][1];

                    int dist = abs(x1-x2) + abs(y1-y2);

                    pq.push({dist,nextnode});
                    
                }
            }
        }
        return total_cost;
    }
};