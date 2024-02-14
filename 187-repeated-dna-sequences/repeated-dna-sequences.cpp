class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.length()<10){
            return {};
        }
        set<string> st,an;
        vector<string> ans;
        for(int i = 0 ; i <= s.length()-10;i++){
            string str = s.substr(i,10);
            if(st.find(str)!=st.end()){
                an.insert(str);
            }else{
                st.insert(str);
            }
        }
        for(auto i : an){
            ans.push_back(i);
        }
        return ans;
    }
};