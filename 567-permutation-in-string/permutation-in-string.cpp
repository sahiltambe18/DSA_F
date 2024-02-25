class Solution {
    bool eq(vector<int> &mp , vector<int> &nmp ){
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
        vector<int> mp(26,0) , nmp(26,0);

        int k = s1.length() , n = s2.length() ;
        if(k>n) return false;
        int i = 0;

        for( i ; i < k ; i++){
            mp[s1[i]-'a']++;
            nmp[s2[i]-'a']++;
        }

        // check for eq
        if(eq(mp,nmp)){
            return true;
        }
        
        for( i  ; i < n;i++){
            nmp[s2[i]-'a']++;
            nmp[s2[i-k]-'a']--;
            // check eq
            
            if(eq(mp,nmp)){
                return true;
            }
        }
        return false;
    }
};