class Solution {
public:
    string removeKdigits(string num, int k) {
        
        string ans = "";
        for(auto i : num){
            while(!ans.empty() && ans.back()>i && k>0){
                ans.pop_back();
                // st.push(i);
                k--;
            }
            if(!ans.empty() || i!='0'){
                ans+=i;
            }
        }
        
        while(!ans.empty() && k > 0){
            ans.pop_back();
            k--;
        }
        
        if(ans.empty())return "0";
        int n = ans.length();
        return ans.substr(0,n-k);
    }
};