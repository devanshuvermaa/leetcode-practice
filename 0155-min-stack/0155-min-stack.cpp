class MinStack {
    stack<int> s;
    stack<int> minstack;
public:
    MinStack() {
        
    }
    
    void push(int value) {
        if(s.empty()){
            s.push(value);
            minstack.push(value);
        }else{
            s.push(value);
            if(minstack.top() >= value){
                minstack.push(value);
            }
        }
    }
    
    void pop() {
        if(s.top() == minstack.top()){
            minstack.pop();
        }
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return minstack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */