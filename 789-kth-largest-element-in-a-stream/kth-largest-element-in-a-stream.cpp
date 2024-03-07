class KthLargest {
    vector<int> v;
    int pi ;
public:
    KthLargest(int k, vector<int>& nums) {
        v = nums;
        sort(v.begin(),v.end());
        pi = v.size()-k;
    }
    
    int add(int val) {
        int l = 0 , r = v.size()-1;
        while (l <= r) {
        int mid = l + (r - l) / 2;
        if (v[mid] > val) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
        }
        pi++;
        v.insert(v.begin()+l,val);
        return v[pi];

    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */