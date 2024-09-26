class MyCalendar {
    vector<pair<int,int>> v;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(auto &i: v){
            int s = i.first;
            int e = i.second;
            if(start>= s && start<e) return 0;
            else if(end>s && end<e) return 0;
            else if(start<s && end>=e) return 0;
        }
        v.push_back({start,end});
        return 1;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */