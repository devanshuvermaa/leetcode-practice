class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int left = 0;
        int right = n-1;

        while(left<=right){
            int mid = left + (right - left)/2;
            int maxi = mat[0][mid];
            int r = 0;
            for(int i=0;i<m;i++){
                if(mat[i][mid] > maxi){
                    maxi = mat[i][mid];
                    r = i;
                }
            }

            int leftneigh = mid-1 >= 0 ? mat[r][mid-1] : -1;
            int rightneigh = mid+1 < n ? mat[r][mid+1] : -1;


            if(mat[r][mid] > leftneigh && mat[r][mid] > rightneigh) return {r,mid};
            if(mat[r][mid]<leftneigh){
                right = mid-1;
            }else if(mat[r][mid]<rightneigh){
                left = mid+1;
            }
        }
        return {-1,-1};
    }
};