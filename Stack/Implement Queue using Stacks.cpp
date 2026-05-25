class MyQueue {
public:
    stack<int> first , res;
    MyQueue() {

    }
    
    void push(int x) {
        first.push(x);
    }
    
    int pop() {
        int front = peek();
        if (!res.empty())
            res.pop();
        return front; 
    }
    
    int peek() {
        if (res.empty()){
            while (!first.empty())
                res.push(first.top()) , first.pop();
        }
        int front = -1;
        if (!res.empty())
            front = res.top();
        return front; 
    }
    
    bool empty() {
        return (res.empty() && first.empty());
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