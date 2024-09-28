class MyCircularQueue {
    vector<int> v;
    int size,cnt,fr,end;
public:
    MyCircularQueue(int k) {
        size =k;
        fr = end = -1;
        v.resize(k,-1);
        cnt =0;
    }
    
    bool enQueue(int value) {
        if(isFull()) return 0;
        if(isEmpty()){
            fr = end = 0;
        }else{
            end = (end+1)%size;
        }
        v[end] = value;
        cnt++;
        return 1;
    }
    
    bool deQueue() {
        if(isEmpty()) return 0;
        v[fr] = -1;
        fr= (fr+1)%size;
        cnt--;
        return 1;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return v[fr];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
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
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */