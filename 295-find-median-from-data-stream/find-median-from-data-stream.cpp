class MedianFinder {

    priority_queue<int , vector<int> , greater<int>> lower;
    priority_queue<int> upper;

public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(upper.empty() || num<=upper.top()){
            upper.push(num);
        }else {
            lower.push(num);
        }

        if(upper.size()<lower.size()){
            upper.push(lower.top());
            lower.pop();
        }else if(upper.size()>lower.size()+1){
            lower.push(upper.top());
            upper.pop();
        }
    }
    
    double findMedian() {
        if(upper.size()==lower.size()){
            return (upper.top()+lower.top())/2.0;
        }else{
            return upper.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */