class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if (n == 0) return 0;

        int total = 1;
        int up = 0, down = 0, peak = 0;

        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                ++up;
                down = 0;
                peak = up;
                total += 1 + up;
            } else if (ratings[i] < ratings[i - 1]) {
                ++down;
                up = 0;
                total += 1 + down + (peak >= down ? -1 : 0);
            } else {
                up = down = peak = 0;
                total += 1;
            }
        }

        return total;
    }
};
