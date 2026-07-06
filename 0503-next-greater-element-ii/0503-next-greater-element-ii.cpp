class Solution {
public:
    vector<int> helper(vector<int>& nums) {
        stack<int> s;
        vector<int> ans(nums.size(), 0);
        for (int i = nums.size()-1; i >=0; i--) {
            s.push(nums[i]);
        }

        for (int i = nums.size() - 1; i >= 0; i--) {
            while (!s.empty() && s.top() <= nums[i]) {
                s.pop();
            }
            if(s.empty()){
                ans[i] = -1;
            }else{
                ans[i] = s.top();
            }
            s.push(nums[i]);
        }
        return ans;
    }

    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans = helper(nums);
        return ans;
    }
};