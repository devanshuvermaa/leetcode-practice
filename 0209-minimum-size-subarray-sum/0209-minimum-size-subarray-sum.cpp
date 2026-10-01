class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int left = 0;
        int ans = 1e9;
        int sum=0;

        for(int right=0;right<n;right++){
            sum+=nums[right];


            while(sum > target){
                ans = min(ans,right-left+1);
                sum -= nums[left];
                left++;
            }

            if(sum >= target){
                ans = min(ans,right-left+1);
            }
        }
        if(ans == 1e9) return 0;
        return ans;
    }
};