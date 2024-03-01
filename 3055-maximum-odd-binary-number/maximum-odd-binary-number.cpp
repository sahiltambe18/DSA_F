class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int st = 0 , n = s.length() ;
        int r = n-1 , o = n-1;
        while(s[o]!='1')o--;
        s[o] = '0';
        s[r--] = '1';

        while(st<r){
            if(s[st]=='0'){
                while(s[r]!='1' && r>0) r--;
                if(st<r){

                s[st] = '1';
                s[r] = '0';
                }
                st++;
                r--;
            }else{
                st++;
            }
        }
        return s;
    }
};