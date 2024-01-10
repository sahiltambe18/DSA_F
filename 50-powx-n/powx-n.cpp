class Solution {
public:
    
    double myPow(double x, int num) {
        
        long long n = num;
        double ans = 1;
        bool flag = 1;
        if(n<0) flag = 0;
        n = abs(n);

        while(n>0){
            if(n%2){

            ans*=x;
            n--;
            }else{
                x = x*x;
                n = n/2;
            }
        }

        if(flag){
            return ans;
        }else{
            return 1.0/ans;
        }
    }
};