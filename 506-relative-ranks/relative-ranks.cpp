class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<pair<int, int>> rem;
        vector<string> res(n);

        
        for(int i = 0;i < n;i++)
            rem.push_back({score[i], i});


        sort(rem.begin(), rem.end());


        for(int i = n-1;i >= 0;i--){
            if(i == n-1)res[rem[i].second] = "Gold Medal";
            else if(i == n-2)res[rem[i].second] = "Silver Medal";
            else if(i == n-3)res[rem[i].second] = "Bronze Medal";
            else res[rem[i].second] = to_string(n-i);
        }
        return res;
    }
};