class Solution {
public:
    string reversePrefix(string word, char ch) {
        int r = 0 ;
        int l = word.size();
        while(r<l){
            if(ch==word[r]){
                break;
            }
            r++;
        }
        if(r==l)return word;

        for(int i = 0; i<r ;i++ , r--){
            char c = word[i];
            word[i] = word[r] ;
            word[r] = c;
        }

        return word;

    }
};