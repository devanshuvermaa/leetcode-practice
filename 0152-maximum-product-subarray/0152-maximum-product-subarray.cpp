class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int curr1 = 1;
        int curr2 = 1;
        int maxi = -1e9;

        for(int i=0;i<nums.size();i++){
            curr1 *= nums[i];
            curr2 *= nums[n-1-i];
            maxi = max(maxi,max(curr1,curr2));
            if(curr1 == 0){
                curr1 = 1;
            }
            if(curr2 == 0){
                curr2 = 1;
            }
        }
        return maxi;
    }
};