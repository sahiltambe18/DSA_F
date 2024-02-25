class Solution {
    bool allUsed(unordered_map<char,int> &sc , unordered_map<char,int> &tc){
        for(auto i :tc){
            
            if(i.second>sc[i.first]){
                return false;
            }
        }
        return true;
    }
public:
    string minWindow(string s, string t) {
        if(s.length()<t.length()) return "";

        unordered_map<char,int> sc , tc;
        for(int i = 0 ; i < t.size();i++){
            tc[t[i]]++;
        }

        int start = 0 , end = 0 , n = s.length();
        string ans  = "";

        while(start<=end && end<n){
            
            sc[s[end]]++;

            while(start<=end && sc[s[start]]>=tc[s[start]]){

                string temp = s.substr(start,end-start+1);

                if(allUsed(sc,tc) && (ans.length()>temp.length()||ans=="")){
                    ans = temp;
                }
                if(sc[s[start]]==tc[s[start]]) break;

                sc[s[start]]--;
                start++;
            }
            end++;
        }
        return ans;
    }
};

