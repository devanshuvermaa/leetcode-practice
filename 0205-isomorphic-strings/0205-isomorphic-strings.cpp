class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> stot;
        unordered_map<char,char> ttos;
        for(int i=0;i<s.size();i++){
            if(stot.count(s[i]) && stot[s[i]] != t[i]){
                return false;
            }
            if(ttos.count(t[i]) && ttos[t[i]] != s[i]){
                return false;
            }
            stot[s[i]] = t[i];
            ttos[t[i]] = s[i];
        }
        return true;
    }
};