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
        
        umap['2'] = "abc" ;
        umap['3'] = "def" ;
        umap['4'] = "ghi" ;
        umap['5'] = "jkl" ;
        umap['6'] = "mno" ;
        umap['7'] = "pqrs";
        umap['8'] = "tuv";
        umap['9'] = "wxyz";
        for(auto i : digits){
            ans = bk(ans , umap[i]);
        }
        return ans;
    }
};