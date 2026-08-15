class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        long long left = 0;
        long long right = n-1;

        while(left<=right){
            long long mid = left+(right-left)/2;

            if(nums[mid] == target){
                return true;
            }

            if(nums[left] == nums[mid] && nums[right] == nums[mid]){
                left++;
                right--;
                continue;
            }

            if(nums[left] <= nums[mid]){ //left sorted
                if(nums[left] <= target && nums[mid] > target){
                    right = mid-1;
                }else{
                    left = mid+1;
                }
            }else{//right sorted
                if(nums[mid] < target && nums[right] >= target){
                    left = mid+1;
                    
                }else{
                    right = mid-1;
                }
            }
        }
        return false;
    }
};