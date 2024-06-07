class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        set<string> st(dictionary.begin(), dictionary.end());

        int i = 0, l = sentence.length();
        string ans = "";
        while (i < l) {
            int j = i;
            while (j < l && sentence[j] != ' ')
                j++;
            int k = i;
            while (k < j) {
                string str = sentence.substr(i, k - i );
                if (st.find(str) != st.end()) {
                    if (ans != "") {
                        ans += " ";
                    }
                    ans += str;
                    i = j + 1;
                    // continue;
                    break;
                }
                k++;
            }
            if (i > j)
                continue;
            if (ans != "") {
                ans += " ";
            }
            ans += sentence.substr(i, j - i );
            i = j + 1;
        }
        return ans;
    }
};