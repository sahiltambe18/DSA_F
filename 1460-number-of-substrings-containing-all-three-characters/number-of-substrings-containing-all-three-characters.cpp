class Solution {
public:
    int numberOfSubstrings(string s) {
        int  l = 0 , r = 0 , n = s.length();
        int cnt = 0;
        
        int arr[3] = {0,0,0};
        while(l < n && r < n){
            arr[s[r]-'a']++;
            while(arr[0]>0 && arr[1]>0 && arr[2]>0){
                cnt+= n-r;
                arr[s[l]-'a']--;
                l++;
            }
            r++;
        }
        return cnt;
    }
};