class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);

        int i = 1;
        while(i<n){
            if(intervals[i][0] <= ans.back()[1]){
                ans.back()[1] = max(ans.back()[1],intervals[i][1]);
            }else{
                ans.push_back(intervals[i]);
            }
            i++;
        }
        return ans;
    }
};