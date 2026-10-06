class Solution {
public:

    int helper(string &s,int left,int right){
        int count = 0;
        while(left>=0 && right<s.size() && s[left] == s[right]){
            left--;
            right++;
            count++;
        }
        return count;
    }
    
    int countSubstrings(string s) {
        int n = s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int temp1 = helper(s,i,i);
            int temp2 = helper(s,i,i+1);
            ans = ans+temp1+temp2;
        }

        return ans;
    }
};