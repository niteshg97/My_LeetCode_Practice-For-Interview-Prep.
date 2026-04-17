class MyStack {
public:
    queue<int>q;
    MyStack() {
    // q is initialized automatically
    }
    
    void push(int x) {
        int s=q.size();
        q.push(x);
        for(int i=1;i<=s;i++){
            q.push(q.front());
            q.pop();
        }
        
    }
    
    int pop() {
        int res = q.front();
        q.pop();
        return res;
        
    }
    
    int top() {
        return q.front();
        
    }
    
    bool empty() {
        return q.empty();
        
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */