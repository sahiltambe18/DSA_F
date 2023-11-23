class Solution {
public:
    int make(vector<int>& coins, int amount, map<int,int> &memo){
        
        if(memo.find(amount)!=memo.end()){
            return memo[amount];
        }
        if(amount<0) return -1;
        if(amount==0){
            return 0;
        }
        int minCoins = INT_MAX;
        for (auto coin : coins) {
            int res = make(coins, amount - coin, memo);
            if (res >= 0 && res < minCoins) {
                minCoins = res + 1; 
            }
        }
        memo[amount] = minCoins!=INT_MAX ? minCoins : -1;
        return memo[amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        if(amount==0) return 0;
        
        map<int,int> memo;
        return make(coins , amount , memo );
    }
};