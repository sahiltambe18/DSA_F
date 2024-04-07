
class Solution {
public:
    string getSmallestString(string s, int k) {
        int n = s.size();
        string t = s;

        for (int i = 0; i < n ; i++) {
            int c = s[i]-'a';
            for(int j = 0 ; j < 26 ; j++){
                int diff = min(abs(c-j),26-abs(c-j));
                if (diff <= k) {
                    t[i] = 'a'+j;
                    k -= diff;
                    break;
                }
            }
        }

        return t;
    }
};
