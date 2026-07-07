class Solution {
public:
    vector<int> nseidx(vector<int>& vec) {
        vector<int> ans(vec.size(), 0);
        stack<int> s;
        for (int i = vec.size() - 1; i >= 0; i--) {
            while (!s.empty() && vec[s.top()] >= vec[i]) {
                s.pop();
            }
            if (s.empty()) {
                ans[i] = vec.size();
            } else {
                ans[i] = s.top();
            }
            s.push(i);
        }
        return ans;
    }
    vector<int> pseidx(vector<int>& vec) {
        vector<int> ans(vec.size(), 0);
        stack<int> s;
        for (int i = 0; i < vec.size(); i++) {
            while (!s.empty() && vec[s.top()] > vec[i]) {
                s.pop();
            }
            if (s.empty()) {
                ans[i] = -1;
            } else {
                ans[i] = s.top();
            }
            s.push(i);
        }
        return ans;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int mod = 1e9 + 7;
        auto nse = nseidx(arr);
        auto pse = pseidx(arr);

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += (1LL * arr[i] * (nse[i] - i) * (i - pse[i])) % mod;
        }

        return ans % mod;
    }
};