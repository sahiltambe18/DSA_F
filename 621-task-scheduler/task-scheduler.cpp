class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> mp(26,0);
        priority_queue<int> pq;

        for(char i : tasks){
            mp[i-'A']++;
        }

        for(int i = 0 ; i < 26 ; i++){
            if(mp[i]){
                pq.push(mp[i]); 
            }
        }

        int total = 0;

        while(!pq.empty()){
            int rem = n+1;
            vector<int> remain;

            while(rem && !pq.empty()){
                if(pq.top()>1){
                    remain.push_back(pq.top()-1);
                }
                pq.pop();
                ++total;
                --rem;
            }
            
            for(auto i : remain){
                pq.push(i);
            }

            if(pq.empty()) break;
            total+=rem;
        }
        return total;
    }
};
