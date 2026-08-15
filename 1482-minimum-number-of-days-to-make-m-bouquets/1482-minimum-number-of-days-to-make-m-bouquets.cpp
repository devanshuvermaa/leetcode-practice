class Solution {
public:
    bool isPossible(int mid,vector<int>& nums, int m, int k){
        int count=0;
        int b=0;
        for(int n:nums){
            if(mid>=n){
                count++;
                if(count == k){
                    b++;
                    count=0;
                }
            }else{
                count=0;
            }
        }

        if(b>=m) return true;
        return false;
    }

    int minDays(vector<int>& bloomDay, long long m, long long k) {
        long long n = bloomDay.size();
        long long pro = k*m;
        if(pro > n) return -1;

        int left = *min_element(bloomDay.begin(),bloomDay.end());
        int right = *max_element(bloomDay.begin(),bloomDay.end());
        int ans = right;

        while(left<=right){
            int mid = left+(right-left)/2;

            if(isPossible(mid,bloomDay,m,k)){
                ans = min(ans,mid);
                right = mid-1;
            }else{
                left = mid+1;
            }
        }

        return ans;
    }
};