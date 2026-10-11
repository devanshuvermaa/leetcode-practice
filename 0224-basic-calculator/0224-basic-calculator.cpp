class Solution {
public:
    int calculate(string s) {
        long long num = 0;
        stack<int> st;
        int sign = 1;
        int result = 0;

        for(char ch : s){
            if(isdigit(ch)){
                num = num * 10 + (ch - '0');
            }
            if(ch == '+'){
                result += sign*num;
                num =0;
                sign = 1;
            }
            if(ch == '-'){
                result += sign*num;
                num =0;
                sign = -1;
            }
            if(ch == '('){
                st.push(result);
                st.push(sign);

                result = 0;
                sign = 1;
            }if(ch == ')'){
                result += sign * num;
                num = 0;
                int outersign = st.top();
                st.pop();
                int outerresult = st.top();
                st.pop();

                result = outerresult + outersign * result;
            }
        }

        result += sign * num;
        return result;
    }
};