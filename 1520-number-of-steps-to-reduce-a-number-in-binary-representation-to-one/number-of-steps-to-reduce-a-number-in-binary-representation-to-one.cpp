class Solution {
public:
    int numSteps(string s) {
        int n = s.length();
       int ans = n-1;
       int c = 0;
       
       for(int i = n-1 ; i > 0 ;i--){
        if((s[i]-'0')+c==1){
            ans++;
            c = 1;
        }
       } 
       return ans + c;

    }
};