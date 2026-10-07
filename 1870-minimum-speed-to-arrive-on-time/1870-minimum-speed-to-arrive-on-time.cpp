class Solution {
public:
    bool helper(vector<int>& dist, int speed, double h){
        double hour = 0;
        int n = dist.size();
        for(int i=0;i<n-1;i++){
            hour += (int)(dist[i]+(speed-1))/speed;
        }
        hour += (double)dist[n-1]/speed;
        if(hour <= h) return true;
        return false;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        if(hour<n-1) return -1;

        int st = 1;
        int end = 1e7;
        int ans = -1;

        while(st <= end){
            int mid = st + (end-st)/2;
            if(helper(dist,mid,hour)){
                ans = mid;
                end = mid-1;
            }else{
                st = mid+1;
            }
        }
        return ans;

    }
};