class Solution {
    bool check(vector<int> &a, vector<int> &b){
        for(int i = 0 ; i < 26 ;i++){
            if(a[i]!=b[i]) return 0;
        }
        return 1;
    }
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length()) return 0;
        vector<int> f1(26,0) , f2(26,0);
        for(char &i: s1){
            f1[i-'a']++;
        }
        int i = 0;
        int l = s1.size();
        for(i = 0 ; i <l ; i++){
            f2[s2[i]-'a']++;
        }
        if(check(f1,f2)) return 1;

        l = s2.length();

        int low = 0;

        for(i ; i < l ; i++){
            f2[s2[low++]-'a']--;
            f2[s2[i]-'a']++;

            if(f1[s2[i]-'a']==f2[s2[i]-'a']){
                if(check(f1,f2)) return 1;
            }
        }

        return 0;

    }
};