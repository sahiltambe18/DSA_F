class Solution {
public:
    bool judgeSquareSum(int c) {
        long i = 0;
        
            long n = static_cast<long> (sqrt(c));
            while(i<=n){
                long res = (i*i)+(n*n);
                if(res<c){
                    i++;
                }else if(res>c){
                    n--;
                }else{
                    return true;
                }
            }
        return false;
    }
};