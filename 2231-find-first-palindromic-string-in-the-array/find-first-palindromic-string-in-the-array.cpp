class Solution {
    bool check(string &str ){
        int l = 0, r = str.size()-1;
        while(l<r){
            if(str[l]!=str[r]){
                return false;
            }
            l++ ;
            r--;
        }
        return true;
    }
public:
    string firstPalindrome(vector<string>& words) {
        for(auto i : words){
            if(check(i)){
                return i;
            }
        }
        return "";
    }
};