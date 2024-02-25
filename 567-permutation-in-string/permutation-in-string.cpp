class Solution {
    
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> mp , nmp;
        for(auto i : s1){
            mp[i]++;
        }
        nmp = mp;
        int k = s1.length() , n = s2.length();
        for(int i = 0 ; i <= n-k;i++){
            bool flag = true;
            for(int j = i ; j < i+k ; j++){
                if(nmp.find(s2[j])!=nmp.end() && nmp[s2[j]]>0){
                    nmp[s2[j]]--;
                }else{
                    flag  = false;
                    break;
                }
            }
            if(flag){
                return true;
            }else{
                nmp = mp;
            }
        }
        return false;
    }
};