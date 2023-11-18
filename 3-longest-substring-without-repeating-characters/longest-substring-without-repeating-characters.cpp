class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> umap;
        int ans = 0, start = 0;

        for (int i = 0; i < s.length(); i++) {
            if (umap.find(s[i]) != umap.end() && umap[s[i]] >= start) {
                start = umap[s[i]] + 1;
            }
            umap[s[i]] = i;
            ans = max(ans, i - start + 1);
        }

        return ans;
    }
};
