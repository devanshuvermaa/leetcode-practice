class Solution {
public:
    class info{
    public:
        int u;
        int cost;
        int stops;

        info(int u,int cost,int val){
            this->u=u;
            this->cost=cost;
            this->stops=val;
        }
    };

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        queue<info> q;
        vector<int> dist(n,INT_MAX);
        
        q.push(info(src,0,-1));
        while(!q.empty()){
            info curr=q.front();
            q.pop();

            for(int i=0;i<flights.size();i++){
                if(flights[i][0]==curr.u){
                    int next=flights[i][1];
                    int cost=flights[i][2];

                    if(dist[next]>curr.cost + cost && curr.stops+1<=k){
                        dist[next]=curr.cost+cost;
                        q.push(info(next,dist[next],curr.stops+1));
                    }
                }
            }
        }
        if(dist[dst]==INT_MAX){
            return -1;
        }
        return dist[dst];

    }
};