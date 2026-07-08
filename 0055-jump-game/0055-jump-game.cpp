class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxidx=0;
        for(int i=0;i<n;i++){
            if(i>maxidx) return false;
            int idx = i+nums[i];
            maxidx = max(idx,maxidx);
        }
        return true;
    }
};