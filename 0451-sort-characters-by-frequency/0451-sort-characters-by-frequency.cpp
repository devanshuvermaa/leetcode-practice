class Solution {
public:
    string frequencySort(string s) {
        int n = s.length();
        unordered_map<char ,int> mp;

        for(char ch:s){
            mp[ch]++;
        }

        priority_queue<pair<int,char>> maxheap;
        for(auto p:mp){
            maxheap.push({p.second,p.first});
        }
        string ans = "";
        while(!maxheap.empty()){
            auto curr = maxheap.top();
            maxheap.pop();

            ans.append(curr.first,curr.second);
        }
        return ans;
    }
};