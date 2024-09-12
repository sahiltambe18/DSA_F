class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> st;
        for(auto &i : allowed){
            st.insert(i);
        }
        int cnt =0;

        for(auto &str : words){
            bool flag =1;
            for(auto &c : str){
                if(st.count(c)==0){
                    flag = 0;
                    break;
                }
            }
            if(flag) cnt++;
        }

        return cnt;

    }
};