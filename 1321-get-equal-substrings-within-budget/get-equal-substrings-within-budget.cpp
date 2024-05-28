class Solution {
    int solve(string s, string t, int maxCost ){
        int n = s.length();
        int len = 0;
        int start = 0;
        int currCost = 0;
        for(int i = 0; i<n ; i++){
            currCost+=abs(s[i]-t[i]);

            while(currCost>maxCost){
                currCost-=abs(s[start]-t[start]);
                start++;
            }

            len = max(len , i-start+1);
        }
        // maxLen = max(maxLen,len);
        return len;
    }
public:
    int equalSubstring(string s, string t, int maxCost) {
        int len = solve(s,t,maxCost);
        return len;
    }
};