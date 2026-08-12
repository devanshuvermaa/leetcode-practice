class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int count = 0;
        for(auto ch : s){
            if(ch == '('){
                count++;
                if(count>1){
                    ans+="(";
                }
            }
            else if(ch == ')' && count>1){
                ans+=")";
                count--;
            }else{
                count = 0;
            }
        }

        return ans;
    }
};