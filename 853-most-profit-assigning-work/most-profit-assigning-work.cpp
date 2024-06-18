class Solution {
public:
    struct Compare{
        bool operator()(const pair<int,int> &a , const pair<int,int> &b){
            if(a.first==b.first) return a.second < b.second;
            return a.first > b.first;
        }
    };
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>> v;
        int n = profit.size();

        for(int i = 0 ; i < n ; i++){
            v.push_back({profit[i],difficulty[i]});
        }
        sort(v.begin(),v.end(), Compare());

        // return v[0].second;

        int ans = 0;

        for(auto i: worker){
            for(auto j : v){
                if(j.second<=i){
                    ans+= j.first;
                    break;
                }
            }
        }
        return ans;
    }
};