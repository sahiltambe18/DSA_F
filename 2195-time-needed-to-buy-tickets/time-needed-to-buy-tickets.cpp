#define arr(a) a.begin() , a.end()
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int target  = tickets[k];
        int time = 0;
        queue<pair<int,bool>> q;
        for(int i = 0 ; i < tickets.size() ; i++){
            q.push({tickets[i],i==k});
        }

        while(!q.empty()){
            pair<int,bool> p = q.front();
            q.pop();
            p.first--;
            time++;
            if(p.second && p.first==0){
                return time;
            } 
            if(p.first>0) q.push(p);
        }

        return time;
    }
};