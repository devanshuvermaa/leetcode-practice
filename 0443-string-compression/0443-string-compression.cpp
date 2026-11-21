class Solution {
public:
    int compress(vector<char>& chars) {
        string s="";
        int n = chars.size();

        char curch = chars[0];
        int count = 1;
        for(int i=1;i<n;i++){
            if(curch == chars[i]){
                count++;
            }else{
                s += curch;
                if(count > 1) s += to_string(count);
                curch = chars[i];
                count = 1;
            }
        }
        s += curch;
        if(count > 1) s += to_string(count);

        for(int i=0;i<s.size();i++){
            chars[i] = s[i];
        }
        return s.size();
    }
};