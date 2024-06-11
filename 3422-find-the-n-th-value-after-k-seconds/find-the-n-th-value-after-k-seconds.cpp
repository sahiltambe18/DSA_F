class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        vector<int> v(n,1);
        while(k>0){
            k--;
            for(int i = 1 ; i < n ; i++){
                v[i] += v[i-1];
                v[i]%=1000000007; 
            }
        }
        return v[n-1];
    }
};