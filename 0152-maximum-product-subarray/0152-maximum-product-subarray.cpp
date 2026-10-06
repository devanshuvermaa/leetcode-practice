class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxi = nums[0];
        int mini = nums[0];
        int ans = nums[0];

        for(int i=1;i<n;i++){
           int oldmax = maxi;
           int oldmin = mini;

           maxi = max({
                oldmax * nums[i],
                oldmin * nums[i],
                nums[i]
           });

           mini = min({
                oldmax * nums[i],
                oldmin * nums[i],
                nums[i]
           });

           ans = max({
                maxi,mini,ans
           });
        }
        return ans;
    }
};