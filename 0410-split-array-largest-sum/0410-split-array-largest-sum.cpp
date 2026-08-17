class Solution {
public:

    bool isValid(int mid,vector<int>& nums, int k){
        int subset = 1;
        int sum = 0;
        for(int i=0;i<nums.size();i++){

            if(sum + nums[i] <= mid){
                sum += nums[i];
            }else{
                subset++;
                if(subset>k) return false;
                sum=nums[i];
            }
        }
        if(subset<=k) return true;
        return false;
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int ans =0 ;
        int left = min(nums[0],nums[n-1]);
        int right = 0;
        for(int i= 0;i<n;i++){
            if(left<nums[i]) left = nums[i];
            right += nums[i];
        }

        while(left <= right){
            int mid = left + (right-left)/2;
            if(isValid(mid,nums,k)){
                ans = mid;
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        return ans;
    }
};