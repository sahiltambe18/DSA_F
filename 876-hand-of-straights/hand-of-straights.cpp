class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize!=0){
            return false;
        }

        unordered_map<int ,int> ump;

        for(auto i : hand){
            ump[i]++;
        }

        sort(hand.begin(),hand.end());

        for(int i = 0 ; i < n ; i++){
            int curr = hand[i];
            if(ump[curr]==0)continue;
            for(int j = 0 ; j < groupSize; j++){
                if(ump[curr+j]==0){
                    return false;
                }else{
                    ump[curr+j]--;
                }
            }
        }
        return true;

    }
};