class Solution {
public:

    void reversearr(vector<int>& nums, int st,int end){
        while(st<end){
            swap(nums[st],nums[end]);
            st++;
            end--;
        }
    }

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int v = k%n;
        if(n>1){
            reversearr(nums,0,n-1);
            reversearr(nums,0,v-1);
            reversearr(nums,v,n-1);
        }
        
    }
};