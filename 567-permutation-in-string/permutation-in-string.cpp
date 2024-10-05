class Solution {
    bool check(vector<int> &mp , vector<int> &nmp ){
        int l = 0 ; 
        int r = 25;
        while(l<=r){
            if(mp[l]!=nmp[l] || mp[r]!=nmp[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length()) return 0;
        vector<int> f1(26,0) , f2(26,0);
        
        int i = 0;
        int l = s1.size();
        for(i = 0 ; i <l ; i++){
            f2[s2[i]-'a']++;
            f1[s1[i]-'a']++;
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