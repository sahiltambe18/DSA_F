class Solution {
public:
    int strStr(string haystack, string needle) {
        int l = needle.size();
        for(int i = 0 ; i < haystack.size();i++){
            if(haystack.substr(i,l)==needle){
                return i;
            }
        }
        return -1;
    }
};