class Solution {
    long long int power(int x , long long e){
        if(e<=1) {
            return e==1? x:1;
        }
        long long int ans = power(x,e/2);
        
        if(e%2){
            ans= ans*ans*x;
        }else{
            ans*=ans;
        }
        return ans%=1000000007;
    }
    // long long int power(long long x, long long n){
    //     if(n==0)return 1; if(n==1)return x;
    //     long long int val = power(x, n/2);
    //     if(n%2==0)return (val*val)%1000000007;
    //     else return (val*val*x)%1000000007;
    // }
public:
    int countGoodNumbers(long long n) {
        if(n==0) return 1;
        long long even = n/2 + n%2;
        long long odd = n/2 ;
        return (power(4,odd)*power(5,even))%1000000007;
    }
};


    
    
    // int countGoodNumbers(long long n) {
    //     long long int even = n/2 + n%2, odd = n/2, sum=1;
    //     return (power(5, even) * power(4, odd))%1000000007;
    // }
