class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        int maxl = 0, maxr = 0, sum = 0;
        vector<int> lf(n, 0), rh(n, 0);

        for(int i = 0, j = n-1; i < n && j >= 0; i++, j--) {
             maxl = max(maxl, h[i]);
            maxr = max(maxr, h[j]);
            lf[i] = maxl;
            rh[j] = maxr;
        }

        for(int i = 0; i < n; i++) {
            sum += min(lf[i], rh[i]) - h[i];
        }

        return sum;
    }
};
