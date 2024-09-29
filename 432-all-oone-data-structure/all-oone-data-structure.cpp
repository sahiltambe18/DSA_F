class AllOne {
    set<pair<int,string>> st;
    unordered_map<string ,int> mp;
public:
    AllOne() {
        
    }
    
    void inc(string key) {
        int n = mp[key];
        st.erase({n,key});
        mp[key]++;
        st.insert({n+1,key});
    }
    
    void dec(string key) {
        int n = mp[key];
        st.erase({n,key});
        if(n==1){
            mp.erase(key);
        }else{
            mp[key]--;
            st.insert({n-1,key});
        }
    }
    
    string getMaxKey() {
        if(!st.empty()) return st.rbegin()->second;
        return "";
    }
    
    string getMinKey() {
        if(!st.empty()) return st.begin()->second;
        return "";
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */