class Solution {
public:
    int lengthOfLastWord(string s) {
        int l = s.length()-1;
        if(l==0) return 1;
        int start = 0 , end = 0;
        
            while( l>=0 && s[l]==' ') l--;
            end = l;
            while( l>=0 && s[l]!=' ') l--;
            start = l+1;
        return end-start+1;
    }
};