class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> s;
        string ans="";
        int x = 1;
        for (int i = 0; i < num.size(); i++) {
            while (!s.empty() && s.top() > num[i] && x <= k) {
                s.pop();
                x++;
            }
            if (s.empty() && num[i] == '0') {
                continue;
            }
            s.push(num[i]);
        }
        while (!s.empty() && x <= k) {
            s.pop();
            x++;
        }
        while(!s.empty()){
            ans += s.top();
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        if(ans.length() == 0){
            return ans+'0';
        }
        return ans;
    }
};