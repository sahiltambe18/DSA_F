class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize) return false;

        sort(hand.begin(),hand.end());

        

        unordered_map<int ,int> mp;

        mp[hand[0]]++;
        

        for(int i = 1 ; i < n ; i++){
            
            mp[hand[i]]++;
        }

        for(int i = 0 ; i < n;i++ ){
            if(mp[hand[i]]==0) continue;

            for(int j = 0 ; j < groupSize ; j++){
                int curr = hand[i]+j;
                if(mp[curr]==0){
                    return false;
                }
                mp[curr]--;
            }
        }
        return true;

    }
};