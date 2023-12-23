class Solution {
public:
    bool rotateString(string s, string g) {
        int l = s.length();
        int r = g.length();
        if(l!=r) return false;
        else if(s==g) return true;
        for(int i = 0 ; i < l ; i++){
            s = s.substr(1,l)+s[0];
            if(s==g) return true;
        }
        return false;
    }
};