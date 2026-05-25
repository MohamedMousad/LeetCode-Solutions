class MinStack {
public:
    stack<int> main;
    stack<int> min_st;
    MinStack() {
        
    }
    
    void push(int val) {
        main.push(val);
        if(min_st.empty() || val <= min_st.top())
            min_st.push(val);
    }
    
    void pop() {
        if (main.top() == min_st.top()) {
            min_st.pop();
        }
        main.pop();
    }
    
    int top() {
        return main.top();
    }
    
    int getMin() {
        return min_st.top();
    }
};