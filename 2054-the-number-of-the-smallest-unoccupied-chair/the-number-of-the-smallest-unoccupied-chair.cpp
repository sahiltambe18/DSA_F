class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        priority_queue<vector<int> ,vector<vector<int>> , greater<vector<int>>> pq;
        for(int i = 0 ; i < times.size() ; i++){
            
            pq.push({times[i][0],times[i][1] , i});
        }

        unordered_map<int ,int> mp;

        while(!pq.empty()){
            vector<int> v = pq.top();
            pq.pop();
            int st = v[0] , ed = v[1] , n = v[2];
            int j = 0 ;
            while(1){
                if(mp[j]<= st){
                    mp[j] = ed;
                    break;
                }
                j++;
            }
            if(n==targetFriend){
                return j;
            }
        }

        return 0;
    }
};