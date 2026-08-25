class MinStack {
public:
    std::stack<int> stack;
    MinStack() {
    }
    
    void push(int val) {
        this->stack.push(val);
    }
    
    void pop() {
        this->stack.pop();
    }
    
    int top() {
        return this->stack.top();
    }
    
    int getMin() {
        std::stack<int> tempStack = this->stack;
        int minValue = INT_MAX;
        if(tempStack.empty()){
            return minValue;
        }
        while(!tempStack.empty()){
            int tempMin = tempStack.top();
            minValue = std::min(tempMin, minValue);
            tempStack.pop();
        }
        return minValue;
    }
};
