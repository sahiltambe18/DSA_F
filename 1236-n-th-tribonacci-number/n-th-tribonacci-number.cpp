class Solution {
    int solve(int n , unordered_map<int ,int> &mp){
        if(mp.find(n)!=mp.end()){
            return mp[n];
        }

        if(n==0) return 0;
        if(n<=2) return 1;

        mp[n] = solve(n-1,mp)+solve(n-2,mp)+solve(n-3,mp);
        return mp[n];
    }
public:
    int tribonacci(int n) {
         unordered_map<int ,int> mp;
        return solve(n,mp);
    }
};