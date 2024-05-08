class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size() , idx = 0;
        vector<string> ans(n);
        priority_queue<int> pq;
        unordered_map<int,int> mp;
        for(auto i : score){
            pq.push(i);
            mp[i] = idx;
            idx++;
        }

        idx = 0;

        while(idx < 3 && !pq.empty()){
            if(idx==0){
                ans[mp[pq.top()]] = "Gold Medal";
            }else if(idx==1){
                ans[mp[pq.top()]] = "Silver Medal";
            }else{
                ans[mp[pq.top()]] = "Bronze Medal";
            }
            pq.pop();
            idx++;
        }

        if(idx==n){
            return ans;
        }
        idx++;
        while(!pq.empty()){
                ans[mp[pq.top()]] = to_string(idx);
                idx++;
                pq.pop();
        }

        return ans;
    }
};