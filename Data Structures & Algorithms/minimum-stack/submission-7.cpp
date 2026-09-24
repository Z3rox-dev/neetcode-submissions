class MinStack {
public:
    stack<int> st;
    stack<int> stmin;
    MinStack() {}
    
    void push(int val) {
        st.push(val);
        if(stmin.empty()){
            stmin.push(val);
        }
        else if(val <= stmin.top()){
            stmin.push(val);
        }
    }
    
    void pop() {
        if(st.empty()) return;
        if(stmin.top() == st.top()){
            stmin.pop();
        }
        st.pop();
    }
    
    int top() {
        if(st.empty()) return -1;
        return st.top();
    }
    
    int getMin() {
        if(stmin.empty()) return -1;
        return stmin.top();
    }
};
