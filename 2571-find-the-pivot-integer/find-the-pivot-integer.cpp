class Solution {
public:
    int pivotInteger(int n) {
        if (n==1) return 1;
        int sum =  ((n*n)+n)/2;
        int rem = 0;
        for(int i = 1 ; i < n ; i++){
            rem+=i;
            if(sum==rem) return i;
            sum-=i;
        }
        return -1;
    }
};