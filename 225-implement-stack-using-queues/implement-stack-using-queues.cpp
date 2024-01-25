class MyStack {
    queue<int> q;
public:
    MyStack() {
        // q.clear();
    }
    
    void push(int x) {
        if(q.empty()){
            q.push(x);
            return;
        }
        queue<int> temp;
        temp.push(x);
        while(!q.empty()){
            temp.push(q.front());
            q.pop();
        }
        q = temp;
    }
    
    int pop() {
        int top = q.front();
        q.pop();
        return top;
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