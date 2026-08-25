class MyQueue {
public:
    stack<int> in; 
    stack<int> out;
    MyQueue() {
        
    }
    
    void push(int x) {
        in.push(x);
    }
    
    int pop() {
        while(!in.empty()){
            out.push(in.top());
            in.pop();
        }
        int val = out.top();
        out.pop();

        while(!out.empty()){
            in.push(out.top());
            out.pop();  
        }
        return val;
    }
    
    int peek() {
        while(!in.empty()){
            out.push(in.top());
            in.pop();
        }
        int val = out.top();

        while(!out.empty()){
            in.push(out.top());
            out.pop();  
        }
        return val;  
    }
    
    bool empty() {
      return in.empty();  
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */