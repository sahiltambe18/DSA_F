class Solution {
    int getScore(string &s , string pair , int pt){
        
        string str = "";
        int score = 0;
        for(auto i : s){
            if(i==pair[1] && str.length()>0 && str.back()==pair[0]){
                score+=pt;
                str.pop_back();
            }else{
                str.push_back(i);
            }
        }

        s = str;
        return score;
    }
public:
    int maximumGain(string s, int x, int y) {
        // string pair = x>y ? "ab" : "ba";
        int score = getScore(s , x>y ? "ab":"ba" , max(x,y));
        score = score + getScore(s , x<y ? "ab":"ba" , min(x,y));

        return score;
    }
};