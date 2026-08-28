class MinStack {
public:
    stack<int> st1;
    stack<int> st2;
    MinStack() {}
    
    void push(int val) {
      if(st2.empty()){
        st2.push(val);
      }
      else if(st2.top() >= val){
        st2.push(val);
      }

      st1.push(val);

    }
    
    void pop() {
        if(st1.empty()) return;
        if(st2.top() == st1.top()){
            st2.pop();
        }
        st1.pop();
    }
    
    int top() {
        if(st1.empty()) return -1;
        return st1.top();
    }
    
    int getMin() {
        if(st2.empty()) return -1;
        return st2.top();
    }
};
