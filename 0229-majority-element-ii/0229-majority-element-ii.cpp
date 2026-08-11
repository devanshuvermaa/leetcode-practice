class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int cand1 = 0;
        int cand2 = 0;
        int count1 = 0;
        int count2 = 0;

        for(int i=0;i<nums.size();i++){
            if (nums[i] == cand1) {
                count1++;
            } 
            else if (nums[i] == cand2) {
                count2++;
            } 
            else if (count1 == 0) {
                cand1 = nums[i];
                count1++;
            } 
            else if (count2 == 0) {
                cand2 = nums[i];
                count2++;
            } 
            else {
                count1--;
                count2--;
            }
        }

        count1= 0;
        count2 = 0;
        int lim = nums.size()/3;
        for(int i = 0;i<nums.size();i++){
            if(nums[i] == cand1) count1++;
            else if(nums[i] == cand2) count2++;
        }

        if(count1 > lim) ans.push_back(cand1);
        if(count2 > lim) ans.push_back(cand2);

        return ans;
    }
};