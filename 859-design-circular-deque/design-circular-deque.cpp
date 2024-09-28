class MyCircularDeque {
    vector<int> v;
    int fr ,end,size,cnt;
public:
    MyCircularDeque(int k) {
        v.resize(k,-1);
        fr = -1 , end=-1;    
        size = k;
        cnt=0;
    }
    bool insertFront(int value) {
        if (isFull()) return false;
        if( isEmpty()){
            fr = end =0;
        }else{
        fr = (fr+size-1)%size;
        }
        v[fr] = value;
        cnt++;
        return 1; 
    }
    
    bool insertLast(int value) {
        if (isFull()) return false;
        if( isEmpty()){
            fr = end =0;
        }else{
        end = (end+1)%size;
        }
        v[end] = value;
        cnt++;
        return 1;
    }
    
    bool deleteFront() {
        if(v[fr] == -1) return 0;
        v[fr] = -1;
        fr = (fr+1)%size;
        cnt--;
        return 1;
    }
    
    bool deleteLast() {
        if(v[end] == -1) return 0;
        v[end] = -1;
        end = (end+size-1)%size;
        cnt--;
        return 1;
    }
    
    int getFront() {
        return v[fr];
    }
    
    int getRear() {
        return v[end];
    }
    
    bool isEmpty() {
        
        return cnt==0;
    }
    
    bool isFull() {
        return cnt==size;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */