class MyCalendarTwo {
    set<pair<int, int>> sgl, dbl;

public:
    MyCalendarTwo() {}

    bool book(int start, int end) {
        int cnt = 0;
        for (auto& i : dbl) {
            auto [s, e] = i;
            if (max(s, start) < min(e, end)) {
                return false; 
            }
        }
         set<pair<int, int>> dels;
        for (auto &[s, e] : sgl) {
            if (max(s, start) < min(e, end)) {
                //get common overlap
                dbl.insert({max(s, start), min(e, end)});
                // dels.insert({s, e});
            }
        }
        sgl.insert({start, end});

        return 1;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */