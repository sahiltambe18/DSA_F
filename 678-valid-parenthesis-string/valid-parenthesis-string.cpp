#include <stack>
#include <string>

class Solution {
public:
    bool checkValidString(std::string s) {
        int opened = 0, closed = 0;

        //  * == (
        for (char c : s) {
            if (c == '(' || c == '*') {
                opened++;
            } else {
                closed++;
            }
            if (closed > opened) {
                return false;
            }
        }

        opened = 0;
        closed = 0;

        // * == )
        for (int i = s.size() - 1; i >= 0; --i) {
            char c = s[i];
            if (c == ')' || c == '*') {
                closed++;
            } else {
                opened++;
            }
            if (opened > closed) {
                return false;
            }
        }

        return true;
    }
};
