class Solution {
public:
    int pivotInteger(int n) {
        if (n==1) return 1;
        
        for(int i = 1 ; i < n ; i++){
            if( i*(i+1) == (n+i)*(n-i+1) ) return i;
        }
        return -1;
    }
};