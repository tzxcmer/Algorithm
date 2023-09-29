class MinStack {
public:
    stack<int> data,mins;
    MinStack() {
        mins.push(INT_MAX);
    }
    
    void push(int val) {
        data.push(val);
        mins.push(min(val,mins.top()));
    }
    
    void pop() {
        data.pop();
        mins.pop();
    }
    
    int top() {
        return data.top();
    }
    
    int getMin() {
        return mins.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
