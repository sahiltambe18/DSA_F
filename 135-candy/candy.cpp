class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1); // Initialize candies for all children with 1

        // Iterate until no further adjustments are needed
        bool adjusted = true;
        while (adjusted) {
            adjusted = false;

            // Traverse the ratings array from left to right
            for (int i = 1; i < n; ++i) {
                if (ratings[i] > ratings[i - 1] && candies[i] <= candies[i - 1]) {
                    // If the current child has a higher rating than its left neighbor
                    // and doesn't have more candies than its left neighbor, update candies
                    candies[i] = candies[i - 1] + 1;
                    adjusted = true;
                }
            }

            // Traverse the ratings array from right to left
            for (int i = n - 2; i >= 0; --i) {
                if (ratings[i] > ratings[i + 1] && candies[i] <= candies[i + 1]) {
                    // If the current child has a higher rating than its right neighbor
                    // and doesn't have more candies than its right neighbor, update candies
                    candies[i] = candies[i + 1] + 1;
                    adjusted = true;
                }
            }
        }

        // Calculate the total number of candies
        // int total = 0;
        // for (int candy : candies) {
        //     total += candy;
        // }

        return accumulate(candies.begin(),candies.end(),0);
    }
};
