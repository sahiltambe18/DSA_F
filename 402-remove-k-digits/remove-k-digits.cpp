class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length();
        if(n==k) return "0";
        string ans = "";
        for(int i = 0; i < n; i++){
            while(!ans.empty() && k > 0 && ans.back() > num[i]){
                ans.pop_back();
                k--;
            }
            if(!ans.empty() || num[i] != '0'){
                ans.push_back(num[i]);
            }
        }
        
        while(!ans.empty() && k > 0){
            ans.pop_back();
            k--;
        }
        
        if(ans.empty()) return "0";
        return ans.substr(0, n - k);
    }
};
