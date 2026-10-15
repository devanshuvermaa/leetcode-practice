class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int> mp;
        priority_queue<pair<int,int>> pq; //freq, element

        for(int n :nums){
            mp[n]++;
        }

        for(auto p:mp){
            pq.push({p.second,p.first});
        }
        for(int i=0;i<k;i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};