class Solution {
    vector<string> bk(vector<string> ans , string str1 ){
        vector<string> newAns;
        for(auto i : ans){
            for(auto j : str1){
                newAns.push_back(i+j);
            }
        }
        return newAns;
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits.length()==0) return {};
        unordered_map<char , string> umap;
        vector<string> ans;
        ans.push_back("");
        
        vector<string> v = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        
        for(auto i : digits){
            ans = bk(ans , v[i-'0']);
        }
        return ans;
    }
};