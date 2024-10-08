class Solution {
public:
    int minSwaps(string s) {
        int mx = 0 , swp = 0;
        int open = 0 ;
        int l = s.length()-1;
        while(l>=0 && s[l]!='[') l--;
        for(int i = 0 ; i < l ; i++){
            if(s[i]==']') open++;
            else{
                open--;
            }
            if(mx<open){
                swp++;
                s[l] = ']';
                s[i] = '[';
                l--;
                mx = open;
                open--;
            } 
        }
        return swp;
    }
};