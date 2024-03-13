class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(),s.end());
        sort(g.begin(),g.end());
        int ans = 0;
        int i = s.size()-1;
        int j = g.size()-1;
        if(i < 0 || j< 0) return 0;
        for( j ; j>=0 ; j--){
            if( s[i]>=g[j]){
                ans++;
                i--;
                if(i<0) break;
            }
        }
        return ans;
    }
};