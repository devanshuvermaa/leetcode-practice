class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target1) {
        int n = nums.size();
        vector<vector<int>> ans;
        int a,b,c,d;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(i>0 && nums[i] == nums[i-1]){
                continue;
            }
            a=nums[i];
            for(int j=i+1;j<n;j++){
                if(j>i+1 && nums[j]==nums[j-1]){
                    continue;
                }
                b=nums[j];
                long long target = (long long)target1-(a+b);
                int left = j+1;
                int right = n-1;
                while(left<right){
                    if(nums[left] + nums[right] == target){
                        ans.push_back({a,b,nums[left],nums[right]});
                        left++;
                        right--;

                        while(left<right && nums[left] == nums[left-1]){
                            left++;
                        }
                        while(left<right && nums[right] == nums[right+1]){
                            right--;
                        }
                    }else if(nums[left] + nums[right] < target){
                        left++;
                    }else{
                        right--;
                    }
                }
            }
        }
        return ans;
    }
};