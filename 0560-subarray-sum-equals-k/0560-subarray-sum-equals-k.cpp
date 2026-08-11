class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0] = 1;
        int sum = 0;
        int count = 0;
        for(int i = 0;i<nums.size();i++){
            sum+=nums[i];
            int diff = sum - k;
            if(mp.count(diff)) count+=mp[diff];
            mp[sum]++;
        }
        return count;
    }
};