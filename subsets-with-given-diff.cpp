#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countPartitions(int n, int d, vector<int>& arr) {
        int totalSum = 0;
        for (int num : arr) {
            totalSum += num;
        }
        
        // Check if it's possible to have a valid partition
        if (totalSum < d || (totalSum - d) % 2 != 0) {
            return 0;
        }
        
        int targetSum = (totalSum - d) / 2;
        
        vector<int> dp(targetSum + 1, 0);
        dp[0] = 1;
        const int mod = 1e9 + 7;
        
        for (int num : arr) {
            for (int s = targetSum; s >= num; s--) {
                dp[s] = (dp[s] + dp[s - num]) % mod;
            }
        }
        
        return dp[targetSum];
    }
};

int main()
{

    int n = 5, d = 5;
    vector<int> arr = {1, 3, 3, 2, 1};
    //expd = 0
    Solution s;
    cout << s.countPartitions(n, d, arr);

    return 0;
}