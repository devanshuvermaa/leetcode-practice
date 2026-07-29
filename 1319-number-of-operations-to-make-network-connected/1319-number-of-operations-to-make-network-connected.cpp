class Solution {
public:
    vector<int> par;
    vector<int> rank;
    int find(int node) {
        if (par[node] == node) {
            return node;
        }

        return par[node] = find(par[node]);
    }

    void unionbyrank(int u, int v) {
        int paru = find(u);
        int parv = find(v);

        if (paru == parv) {
            return;
        }

        if (rank[paru] < rank[parv]) {
            par[paru] = parv;
        }else if(rank[paru] > rank[parv]){
            par[parv] = paru;
        }else{
            par[parv] = paru;
            rank[paru]++;
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1){
            return -1;
        }
        par.resize(n);
        rank.resize(n);

        for(int i=0;i<n;i++){
            par[i] = i;
            rank[i] = 1;
        }

        for(auto it:connections){
            int u = it[0];
            int v = it[1];

            if(find(u) != find(v)){
                unionbyrank(u,v);
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(par[i] == i) count++;
        }
        return count-1;
    }
};