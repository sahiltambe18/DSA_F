class CustomStack {
    vector<int> v;
    int i ;
public:
    CustomStack(int maxSize) {
        v.resize(maxSize,-1);
        i = -1;
    }
    
    void push(int x) {
        if(i+1>=v.size()) return;
        v[++i] = x;
    }
    
    int pop() {
        if(i==-1) return -1;
        int ans = v[i];
        i--;
        return ans;
    }
    
    void increment(int k, int val) {
        
        for(int j = 0 ; j < v.size() && j <=i && j<k ; j++){
            v[j]+= val;
        }
        
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */