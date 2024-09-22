class Solution {
    long long count(long long ans , int n){
        long long res = 0;
        long long nxt = ans + 1;
        while(ans<=n){
            res+= min(nxt, (long long) n+1)-ans;
            ans*=10;
            nxt*=10;
        }
        return res;
    }
public:
    int findKthNumber(int n, int k) {
        int i = 1 ;
        long long ans = 1;
        while(i<k){
            int steps = count(ans , n);
            if(i+ steps <= k){
                ans++;
                i+= steps;
            }else{
                ans*=10;
                i++;
            }
        }
        return ans;
    }
};