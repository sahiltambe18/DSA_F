class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int n = tokens.size();
        if(n==0 || tokens[0]>power) return 0;
        if(n==1) return 1;

        int score = 0 , l = 0 , r = n-1 , mx = 0;

        while(l<=r){
            if(tokens[l]<=power ){
                score++;
                power-=tokens[l];
                l++;
                mx = max(mx,score);
            }
            else if(score>0){
                score--;
                power+=tokens[r];
                r--;
            }
            else{
                break;
            }
        }
        //mx = max(mx,score);

        return mx;
    }
};