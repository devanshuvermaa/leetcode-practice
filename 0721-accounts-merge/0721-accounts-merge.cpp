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
        } else if (rank[paru] > rank[parv]) {
            par[parv] = paru;
        } else {
            par[parv] = paru;
            rank[paru]++;
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        par.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; i++) {
            par[i] = i;
        }

        unordered_map<string, int> mp;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                if (mp.find(accounts[i][j]) == mp.end()) {
                    mp[accounts[i][j]] = i;
                } else {
                    unionbyrank(i, mp[accounts[i][j]]);
                }
            }
        }

        vector<vector<string>> merged(n);
        for (auto it : mp) {
            string mail = it.first;
            int node = find(it.second);

            merged[node].push_back(mail);
        }

        vector<vector<string>> ans;

        for (int i = 0; i < n; i++) {

            if (merged[i].empty()) {
                continue;
            }

            sort(merged[i].begin(), merged[i].end());

            vector<string> temp;

            temp.push_back(accounts[i][0]);

            for (string email : merged[i]) {
                temp.push_back(email);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};