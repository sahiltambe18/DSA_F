class Solution {
public:
    int minAddToMakeValid(string s) {
        // stack<char> st;
        int open = 0 , closed = 0;
        for(auto &i: s){

            if(i==')' && open>0) open--;
            else if(i==')'){
                closed++;
            }else{
                open++;
            }
        }
        return open+closed;
    }
};