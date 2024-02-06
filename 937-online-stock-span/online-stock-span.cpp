class StockSpanner {
    stack<int> st , sp;
public:
    StockSpanner() {
    }
    
    int next(int price) {
        if(st.empty() || st.top()>price){
            st.push(price);
            sp.push(1);
            return 1;
        }
        int span = 1;
        while(!st.empty() && st.top()<=price){
            st.pop();
            span+= sp.top();
            sp.pop();
        }
        st.push(price);
        sp.push(span);
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */