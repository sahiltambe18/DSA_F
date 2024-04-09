#define arr(a) a.begin() , a.end()
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tik, int k) {
        int target  = tik[k];
        int time = 0 , n =  tik.size();
        queue<pair<int,bool>> q;
        for(int i = 0 ; i <=k ; i++){
            time+=min(target,tik[i]);
        }
        target--;
        for(int i = k+1 ; i<n ; i++){
            time+=min(target,tik[i]);
        }

        return time;
    }
};