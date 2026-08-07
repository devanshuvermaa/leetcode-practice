class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();

        vector<int> prev(n+1,0);
        vector<int> curr(n+1,0);

        for(int i = 1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(word1[i-1] == word2[j-1]){
                    curr[j] = 1+prev[j-1];
                }else{
                    curr[j] = max(prev[j],curr[j-1]);
                }
            }
            swap(curr,prev);
        }

        int len = prev[n];
        
        return (m-len) + (n-len);
    }
};