class Solution {
public:
    bool eat(long long speed,vector<int>& piles, long long h){
        long long time = 0;
        for(int i=0;i<piles.size();i++){
            time += ((piles[i]+speed)-1)/speed;
        }
        if(time<=h) return true;
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int left = 1;
        int right = *max_element(piles.begin(),piles.end());
        int ans=right;

        while(left<=right){
            int mid = left + (right - left)/2;
            if(eat(mid,piles,h)){
                ans = min(ans,mid);
                right = mid-1;
            }else{
                left = mid+1;
            }
        }

        return ans;
    }
};