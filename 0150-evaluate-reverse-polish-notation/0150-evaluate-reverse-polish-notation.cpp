class Solution {
public:
    int converttoint(string s){
        int num = 0;
        int sign = 1;
        int i=0;

        if(s[0] == '-'){
            sign = -1;
            i++;
        }
        for(;i<s.size();i++){
            num = num * 10 +(s[i] - '0');
        }
        return sign * num;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(string token : tokens){
            if(token == "+" || token == "-" || token == "*" || token == "/"){
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();

                if(token == "+"){
                    st.push(a+b);
                }else if(token == "-"){
                    st.push(a-b);
                }else if(token == "*"){
                    st.push(a*b);
                }else if(token == "/"){
                    st.push(a/b);
                }
            }else{
                st.push(converttoint(token));
            }
        }
        return st.top();
    }
};