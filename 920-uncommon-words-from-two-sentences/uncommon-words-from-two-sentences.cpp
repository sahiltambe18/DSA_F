class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> ans;
        int l1 = s1.length();
        unordered_map<string,int> st;
        for(int i = 0 ; i< l1 ;i++){
            while(i<l1 && s1[i]==' ') i++;
            int j = i;
            while(j<l1 && s1[j]!=' ') j++;
            string str = s1.substr(i,j-i);
            st[str]++;
            i = j;
        }
        int l2 = s2.length();
        for(int i = 0 ; i < l2 ; i++){
            while(i<l2 && s2[i]==' ') i++;
            int j = i;
            while(j<l2 && s2[j]!=' ') j++;
            string str = s2.substr(i,j-i);
            st[str]++;
            i = j;
        }
        for(auto &i : st){
            if(i.second==1){
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};