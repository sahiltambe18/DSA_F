class Solution {
public:
    int myAtoi(string s) {
        long ans = 0;
        int i = 0;
        bool flag = false;
        
        while(s[i]==' ') i++;
        if(s[i]=='-'){
            flag = true;
            i++;
        }else if(s[i]=='+') i++;

        while(i<s.length()){
            char curr = s[i];
            if(curr>='0' && curr<='9'){
                ans = ans*10 + (curr-'0');
                if(ans>INT_MAX){
                    return flag ? INT_MIN : INT_MAX;
                }
            }else{
                break;
            }
            i++;
        }
        
        return flag ? -ans : ans;
        
    }
};
