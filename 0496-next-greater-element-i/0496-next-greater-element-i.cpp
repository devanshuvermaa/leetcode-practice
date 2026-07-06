class Solution {
public:
    vector<int> helper(vector<int>& vec) {
        int n = vec.size();
        stack<int> s;
        vector<int> ans(n, 0);

        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && s.top() <= vec[i]) {
                s.pop();
            }
            if (s.empty()) {
                ans[i] = -1;
            } else {
                ans[i] = s.top();
            }
            s.push(vec[i]);
        }
        return ans;
    }

    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans=helper(nums2);

        unordered_map<int,int> map;
        for(int i=0;i<nums2.size();i++){
            map[nums2[i]] = ans[i];
        }
        
        vector<int> res;
        for(int i=0;i<nums1.size();i++){
            res.push_back(map[nums1[i]]);
        }
        
        return res;
    }
};