class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();

        int i=n1-1;
        int j = n2-1;


        while(i>=0 || j>=0){
            int del1 = 0;
            int del2 = 0;
           
            while(i>=0){
                if(s[i] == '#'){
                    del1++;
                    i--;
                }else if(del1>0){
                    del1--;
                    i--;
                }else{
                    break;
                }
            }

            while(j>=0){
                if(t[j] == '#'){
                    del2++;
                    j--;
                }else if(del2>0){
                    del2--;
                    j--;
                }else{
                    break;
                }
            }

            if((i>=0) != (j>=0)) return false;
            if(i>=0 && j>=0 && s[i] != t[j]) return false;

            i--;
            j--;
            
        }
        return true;
    }
};