class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        reverse(s.begin(),s.end());

        int l = 0; //write
        int r = 0; //read

        while(r<n){
            while(r<n && s[r] == ' '){
                r++;
            }
            if(r == n){
                break;
            }

            if(l>0){
                s[l] = ' ';
                l++;
            }
            int start = l;
            while(r<n && s[r]!=' '){
                s[l] = s[r];
                l++;
                r++;
            }

            reverse(s.begin()+start,s.begin()+l);

        }
        s.resize(l);
        return s;
    }
};