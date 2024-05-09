class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long ans = 0;
        sort(happiness.begin(),happiness.end());
        int j = 0;
        for(int i = happiness.size()-1 ; i >=0  && j < k; i--){
            ans+= happiness[i]-j >=0 ? happiness[i]-j : 0;
            j++;
        }
        return ans;
    }
};