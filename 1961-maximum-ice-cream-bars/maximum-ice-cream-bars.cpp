class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        if(costs[0]>coins) return 0;
        int ans = 0;
        for(auto &i : costs)
        {
            if(i>coins) return ans;
            coins-=i;
            ans++;
            // if()
        }
        return ans;
    }
};