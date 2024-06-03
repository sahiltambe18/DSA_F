class Solution {
public:
    int appendCharacters(string s, string t) {
        int i = 0 , j = 0;
        int n = s.length() , l = t.length();

        // int ans =0;

        while(i<n && j < l){

            if(s[i]==t[j]){
                i++,j++;
            }else{
                i++;
            }
        }

        if(j>=l) return 0;
        else{
            return l-j;
        }

    }
};