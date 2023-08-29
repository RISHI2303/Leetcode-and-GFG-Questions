class MyStack {
public:
queue <int> q , q2;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        if (q.empty()) return 0;
        else {
            while (q.size() != 1){
                q2.push(q.front());
                q.pop();
            }
            int removed = q.front();
            while (!q.empty()) q.pop();
            while (!q2.empty()) q.push(q2.front()) , q2.pop();
            return removed;
        }
        
    }
    
    int top() {
        return q.back();
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