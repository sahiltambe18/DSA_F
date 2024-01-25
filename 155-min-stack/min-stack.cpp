class MinStack {
    vector<int> v , minv;
    int i;
public:
    MinStack() {
        i = -1;
    }
    
    void push(int val) {
        if(i==-1){
            i++;
            minv.push_back(val);
            v.push_back(val);
        }else{
            minv.push_back(min(minv[i],val));
            v.push_back(val);
            i++;
        }
    }
    
    void pop() {
        minv.pop_back();
        v.pop_back();
        i--;
    }
    
    int top() {
        return v[i];
    }
    
    int getMin() {
        return minv[i];
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