class Solution {
public:
    int myAtoi(string s) {
        long long ans = 0;
        bool flag = false, st = false;
        for (char curr : s) {
            if (curr == ' ' && !st) continue; // Skip space

            if (isdigit(curr)) {
                ans = ans * 10 + (curr - '0');
                st = true;

                if (ans > INT_MAX) return flag ? INT_MIN : INT_MAX; // Overflow 
            } else if (curr == '-' && !st) {
                flag = true;
                st = true;
            } else if (curr == '+' && !st) {
                st = true;
            } else {
                break; 
            }
        }
        
        return flag ? -ans : ans;
    }
};
