class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.empty()) return arr;
        vector<int> v = arr;
        sort(begin(v),end(v));
        int n = v.size();
        unordered_map<int,int> mp;
        mp[v[0]] = 1;
        for(int i = 1 ; i < n ; i++){
            if(v[i]!=v[i-1]){
                mp[v[i]] = mp[v[i-1]]+1;
            }
        }
        for(int i = 0 ; i < n ; i++){
            arr[i] = mp[arr[i]];
        }
        return arr;
    }
};