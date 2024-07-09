class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double ans = 0;
        int curr = customers[0][0];
        for(auto cs : customers){

            if(cs[0]>curr) curr = cs[0];
            curr+= cs[1];
            ans+= curr - cs[0];
        }
        ans/=customers.size();
        return ans;
    }
};