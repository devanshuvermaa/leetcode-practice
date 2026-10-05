class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n,0);
        vector<int> suffix(n,0);
        int leftsum = 0;
        for(int i=0;i<n;i++){
            prefix[i] = leftsum;
            leftsum += nums[i];
        }

        int rightsum = 0;
        for(int i=n-1;i>=0;i--){
            suffix[i] = rightsum;
            rightsum += nums[i];
        }

        for(int i=0;i<n;i++){
            if(prefix[i] == suffix[i]) return i;
        }
        return -1;
    }
};