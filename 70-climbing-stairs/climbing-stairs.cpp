class Solution {
public:
    int climbStair(int n, unordered_map<int, int> &map) {
        if (map.find(n) != map.end()) {
            return map[n];
        }
        if (n <= 1) {
            return 1;
        }
        int result = climbStair(n - 1, map) + climbStair(n - 2, map);
        map[n] = result;
        return result;
    }
    
    int climbStairs(int n) {
        unordered_map<int, int> memo;
        return climbStair(n, memo);
    }
};