class Solution {
public:
    int findTheLongestSubstring(string s) {
        vector<int> mapy(32, -2);
        mapy[0] = -1;

        int maxLen = 0;
        int mask = 0;

        unordered_map<char,int> mp;
        mp['a'] = 1;
        mp['e'] = 2;
        mp['i'] = 4;
        mp['o'] = 8;
        mp['u'] = 16;


        for (int i = 0; i < s.size(); ++i) {
            char ch = s[i];

            if(mp[ch]>0){
                mask^=mp[ch];
            }

            int prev = mapy[mask];
            if (prev == -2) {
                mapy[mask] = i;
            } else {
                maxLen = max(maxLen, i - prev);
            }
        }

        return maxLen;
    }
};