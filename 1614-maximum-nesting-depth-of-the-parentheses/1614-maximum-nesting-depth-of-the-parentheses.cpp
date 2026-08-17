class Solution {
public:
    int maxDepth(string s) {
        int open = 0;
        int maxi = 0;
        for(char ch : s){
            if(ch == '('){
                open++;
                maxi = max(maxi,open);
            }else if(ch == ')'){
                open--;
            }else{
                continue;
            }
        }
        return maxi;
    }
};