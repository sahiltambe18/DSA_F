#include<iostream>
#include<vector>
using namespace std;

class Solution{

	public:
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        const int MOD = 1e9 + 7;
        vector<int> dp(sum + 1, 0);
        dp[0] = 1;
        
        for (int i = 0; i < n; i++) {
            for (int s = sum; s >= 0; s--) {
                if (s >= arr[i]) {
                    dp[s] = (dp[s] + dp[s - arr[i]]) % MOD;
                }
            }
        }
        
        return dp[sum];
	}
	  
};


int main() {
    Solution s;
    int arr[] = {5, 2, 3, 10, 6, 8};
    s.perfectSum(arr , 6 ,10);    
    return 0;
}