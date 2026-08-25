class MinStack {
public:
    std::stack<int> stack;
    std::stack<int> minStack;
    MinStack() {
    }
    
    void push(int val) {
        this->stack.push(val);
        if(minStack.empty() || val <= minStack.top()){
            minStack.push(val);
        }
    }
    
    void pop() {
        if(stack.top() == minStack.top()){
            stack.pop();
            minStack.pop();
        }
        else{
            stack.pop();
        }
    }
    int top() {
        return this->stack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
