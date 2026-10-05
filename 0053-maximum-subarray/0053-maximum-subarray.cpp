class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currsum = 0;
        int maxsum = -1e9;
        for(int i=0;i<nums.size();i++){
            currsum += nums[i];
            maxsum = max(maxsum,currsum);
            if(currsum < 0){
                currsum = 0;
            }
        }
        return maxsum;
    }
};