class Solution {
public:
    string longestCommonPrefix(vector<string>& v) {
        string ans="";
        sort(v.begin(),v.end());
        string first = v[0];
        string last = v[v.size()-1];

        int n = first.size()>last.size()? last.size():first.size();

        for(int i = 0 ; i < n ;i++){
            if(first[i]!=last[i]) return ans;
            ans+=first[i];
        } 

        return ans;
    }
};