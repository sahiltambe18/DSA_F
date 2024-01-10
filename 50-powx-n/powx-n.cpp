class Solution {
public:
    
    double myPow(double x, int num) {
        
        if(num==0) return 1;

        double ans = 1;
        if(num%2){
            ans = x* myPow(x,abs(num)-1);
        }else{
            ans = myPow(x*x,abs(num)/2);
        }

        if(num>0){
            return ans;
        }
        return 1.0/ans;

    }
};