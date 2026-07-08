class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int jumps = 0;
        int currzoneend = 0;
        int farthestidx = 0;
        for(int i=0;i<n-1;i++){
            int idx = i + nums[i];
            farthestidx = max(idx,farthestidx);

            if(i==currzoneend){
                jumps++;
                currzoneend = farthestidx;
            }
        }
        return jumps;
    }
};