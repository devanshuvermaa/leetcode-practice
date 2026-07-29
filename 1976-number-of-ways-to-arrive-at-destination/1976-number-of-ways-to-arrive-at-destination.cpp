class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,long long>>> adj(n);
        for(auto &it : roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<long long> ways(n, 0);
        vector<long long> time(n, 1e18);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>> pq;
        
        pq.push({0,0});
        ways[0]=1;
        time[0]=0;
        int mod = 1e9 + 7;

        while(!pq.empty()){
            int node = pq.top().second;
            int currtime = pq.top().first;
            pq.pop();
            
            if(currtime>time[node]) continue;

            for(auto it : adj[node]){
                int nextnode = it.first;
                long long wt = it.second;

                if(time[nextnode] > time[node]+wt){
                    ways[nextnode] = ways[node];
                    time[nextnode] = time[node]+wt;
                    pq.push({time[nextnode],nextnode});
                }else if(time[nextnode] == time[node]+wt){
                    ways[nextnode] = (ways[node] + ways[nextnode]) % mod;
                }
            }
        }
        return ways[n-1] % mod;
    }
};