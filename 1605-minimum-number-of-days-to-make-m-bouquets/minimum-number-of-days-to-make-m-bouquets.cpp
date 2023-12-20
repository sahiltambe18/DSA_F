class Solution {
    bool isPossible(vector<int>& bloomDay, int m, int k , int days){
        int bq = 0;
        
        int ans = 0;
        for (int i = 0; i < bloomDay.size(); ++i) {
            if (bloomDay[i] <= days) {
                ans++;
                if (ans == k) {
                    bq++;
                    ans = 0;
                }
            } else {
                ans = 0;
            }
        }
        return m<=bq;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if ((long)m * (long)k > (long)n) return -1;

        int l = *min_element(bloomDay.begin(),bloomDay.end()) , r = *max_element(bloomDay.begin(),bloomDay.end());

        while(l<r){
            int mid = l + (r-l)/2;
            if(isPossible(bloomDay , m , k , mid)){
                r = mid;
            }else{
                l = mid+1;
            }
        }
        return l;
    }
};