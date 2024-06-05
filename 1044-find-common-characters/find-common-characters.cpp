class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int>minFreq(26,INT_MAX);
        vector<string> ans;
        int n = words.size();

        for(auto i : words){
            
            vector<int>freq(26,0);
            for(auto j : i){
                freq[j-'a']++;

            }
            for(int j = 0 ; j < 26; j++){
                minFreq[j] = min(freq[j],minFreq[j]);
            }
        }

        for(int j = 0 ; j < 26; j++){
            while(minFreq[j]>0){
                ans.push_back(string(1,(j+'a')));
                minFreq[j]--;
            }
        }
        
        return ans;
    }
};