class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> st(k,0);
        for(int &i : arr){
            st[((i%k)+k)%k]++;
            // st.push_back(i%k);
        }

        // int l = *min_element(st.begin(),st.end()) , r = k-1;
        for(int i = 1 ; i < k ; i++){

            int a = st[i];
            int b = st[k-i];
            if(a!=b){
                return 0;
            }
        
        }
        if(st[0]%2==1) return 0;
        return 1;
    }
};