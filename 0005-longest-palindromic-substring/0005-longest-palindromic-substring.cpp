class Solution {
public:

    int getlength(int left,int right,string &s){
        while(left>=0 && right<s.length() && s[left] == s[right]){
            left--;right++;
        }
        return right-left-1;
    }

    string longestPalindrome(string s) {
        int n = s.length();
        int maxcount = 0;
        int start = 0;
        for(int i=0;i<n;i++){
            int count1 = getlength(i,i,s);
            int count2 = getlength(i,i+1,s);
            
            if(max(count1,count2) > maxcount){
                maxcount = max(count1,count2);
                start = i-(maxcount-1)/2;
            }


        }
        return s.substr(start,maxcount);
    }
};