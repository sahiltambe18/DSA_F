class RandomizedSet {
    unordered_map<int,int> mp;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val)!=mp.end()){
            return false;
        }
        mp[val] = val;
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val)!=mp.end()){
            mp.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int n = rand()%mp.size();
        return next(mp.begin(), n)->second;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */