class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int r = 0;
        int w = 0;

        while (r < n) {
            if (nums[r] == nums[w]){
                r++;
                continue;
            }

            w++;
            nums[w] = nums[r];

        }
        return w+1;
    }
};