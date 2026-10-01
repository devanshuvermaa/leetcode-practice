class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        int count=0;
        int product = 1;

        for(int right = left;right<n;right++){
            product *= nums[right];

            while(product > k){
                product /= nums[left];
                left++;
            }

            if(product < k){
                count += right-left+1;
            }
        }
        return count;
    }
};