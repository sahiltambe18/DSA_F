class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.length()<10){
            return {};
        }
        vector<string> ans;
        unordered_map<string,int> ump;
        for(int i = 0 ; i <= s.length()-10;i++){
            ump[s.substr(i,10)]++;
        }
        for(auto i : ump){
            if(i.second>1){
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};