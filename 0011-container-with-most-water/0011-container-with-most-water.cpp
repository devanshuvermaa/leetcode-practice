class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n-1;
        int maxi = 0;

        while(left < right){
            int water = min(height[left],height[right]) * (right-left);
            maxi = max(maxi,water);

            if(height[left] < height[right]) left++;
            else right--;
        }
        return maxi;
    }
};