class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end(),greater<int>());
        sort(s.begin(),s.end(),greater<int>());
        cout<<g[0];
        int i = 0 , j = 0;
        int n = g.size();
        int n2 = s.size();
        while(i<n && j < n2){
            if(s[j]>=g[i]) j++ ;
            i++;
        }
        return j;
    }
};