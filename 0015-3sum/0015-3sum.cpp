class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(i>0 && nums[i] == nums[i-1]) continue;
            int target = 0-nums[i];
            int st = i+1;
            int end = n-1;
            while(st < end){
                if(st > i+1 && nums[st] == nums[st-1]) st++;
                else if(nums[st] + nums[end] == target){
                    ans.push_back({nums[i],nums[st],nums[end]});
                    st++;end--;
                }else if(nums[st] + nums[end] < target){
                    st++;
                }else{
                    end--;
                }
            }
        }
        return ans;
    }
};