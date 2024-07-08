class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> v(n+1,0);
        int rem = n;

        int idx = 1;
        while(rem>1){
            int j = k;
            while(j>1){
                idx = (idx+1)%n;
                if(v[idx]==0){
                    j--;
                }
            };

            v[idx] = 1;
            rem--;
            while(v[idx]!=0) idx = (idx+1)%n;
        }
        for(int i = 1 ; i <=n ;i++){
            if(v[i]==0){
                return i;
            }
        }
        return -1;
    }
};