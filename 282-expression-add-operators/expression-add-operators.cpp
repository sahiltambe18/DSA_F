class Solution {
private:
    void bk(string &num, int target, int idx, string sol, long long curRes, long long prevNum, vector<string> &ans) {
        if (idx == num.length()) {
            if (curRes == target) {
                ans.push_back(sol);
            }
            return;
        }

        for (int i = idx; i < num.length(); ++i) {

            string currentStr = num.substr(idx, i - idx + 1);
            
            long long currentNum = stoll(currentStr);

            if (idx == 0) {
                bk(num, target, i + 1, sol + currentStr, currentNum, currentNum, ans);
            } else {
                bk(num, target, i + 1, sol + "+" + currentStr, curRes + currentNum, currentNum, ans);
                bk(num, target, i + 1, sol + "-" + currentStr, curRes - currentNum, -currentNum, ans);
                bk(num, target, i + 1, sol + "*" + currentStr, curRes - prevNum + prevNum * currentNum, prevNum * currentNum, ans);
            }

            if (currentNum == 0) {
                // Avoid leading zeros in subsequent numbers
                break;
            }
        }
    }

public:
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        if (num.empty()) {
            return ans;
        }
        bk(num, target, 0, "", 0, 0, ans);
        return ans;
    }
};
