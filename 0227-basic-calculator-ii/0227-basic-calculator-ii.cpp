class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        int num = 0;
        stack<int> st;
        char op ='+';

        for(int i=0;i<=n;i++){
            char c = (i==n)?'+':s[i];

            if(c>='0' && c<='9'){
                num = num * 10 + (c-'0');
            }

            if( (c <'0' || c >'9') && c != ' '){
                if(op == '+'){
                    st.push(num);
                }
                if(op == '-'){
                    st.push(-num);
                }
                if(op == '*'){
                    int x = st.top();
                    st.pop();
                    st.push(x*num);
                }
                if(op == '/'){
                    int x = st.top();
                    st.pop();
                    st.push(x/num);
                }
                op = c;
                num = 0;
            }
        }
        int ans = 0;

        while(!st.empty()){
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};