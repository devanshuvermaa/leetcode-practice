class Solution {
public:
    vector<int> par;
    int find(int node){
        if(par[node] == node){
            return node;
        }
        return par[node] = find(par[node]);
    }
    void unionby(int a,int b,int &count){
        int para=find(a);
        int parb = find(b);

        if(para!=parb){
            par[parb] = para;
            count--;
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        par.resize(stones.size());
        for(int i=0;i<stones.size();i++){
            par[i] = i;
        }

        int cluster_count = stones.size();

        for(int i=0;i<stones.size();i++){
            for(int j=i+1;j<stones.size();j++){
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                    unionby(i,j,cluster_count);
                }
            }
        }
        return stones.size()-cluster_count;
    }
};