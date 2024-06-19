class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
     int l = 1 , r = *max_element(bloomDay.begin(), bloomDay.end());
     int ans = INT_MAX , n = bloomDay.size();
     while(l<=r){
        int mid = l+(r-l)/2;
        int i = 0;
        int bq = 0;
        int collected = 0;
        while(i<n){
            if(bloomDay[i]<=mid){
                bq++;
            }else{
                collected += bq/k;
                // return collected;
                bq = 0;
            }
            i++;
        }
        collected+=bq/k;
        // return collected;
        if(collected>=m){
            ans = min(ans,mid);
            r = mid-1;
        }else{
            l = mid+1;
        }
        if(l>ans) break;
     }   
     return ans == INT_MAX ? -1 : ans;
    }
};