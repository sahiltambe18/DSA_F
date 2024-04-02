class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string str = to_string(n);
        int l = str.length();
        int pivot = l;
        for(int i = l - 1; i > 0; i--) {
            if(str[i] < str[i - 1]) {
                pivot = i;
                str[i - 1]--; 
            }
        }
        for(int i = pivot; i < l; i++) {
            str[i] = '9'; // Set all digits after pivot to '9'
        }
        return stoi(str);
    }
};
