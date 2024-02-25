class Solution {
public:
    string minWindow(string s, string t) {
        string answer;


        vector<int> count(58, 0);
        int unmatched = 0;

        int lowestLength = INT_MAX;
        int answerStart = 0;

        for(char c: t){
            if(count[c-'A'] == 0){
                unmatched ++;
            }
            count[c-'A']++;
        }

        int j = 0;

        for(int i = 0; i<s.length(); i++){
            
            count[s[i]-'A']--;

            if(count[s[i]-'A'] == 0){
                unmatched--;
            }

            while(j<=i && unmatched == 0){
                if(i-j+1 < lowestLength){
                    answerStart = j;
                    lowestLength = i-j+1;
                }
                count[s[j]-'A']++;
                if(count[s[j]-'A'] > 0){
                    unmatched++;
                }
                j++;

            }

            //i represents front of window
            
            //if unmatched is 0 then it's valid
            //i can increment j, and increment count of that val.
            //if the count becomes positive, then unmatched must increase
        }

        if(lowestLength != INT_MAX){
            answer = s.substr(answerStart, lowestLength);
        }
        return answer;
        
    }
};