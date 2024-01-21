class Solution {
public:
    int addDigits(int num) {
        int res = 0;
        while(true){
            res+= num%10;
            num= num/10;
            if(num/10==0){
                res+= num;
                if(res/10==0){
                    return res;
                }else{
                    num = res;
                    res = 0;
                }
            }
        }
        
    }
};