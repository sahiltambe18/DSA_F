class Solution {
    bool check(vector<int>& weights, int days,int cap){
        int  d = 0;
        int c = 0;
        for(auto i : weights){
            if(c+i<=cap){
                c+=i;
            }else{
                d++;
                c=i;
            }
        }
        if(c>0) d++;
        return d<=days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(),weights.end()) , r = accumulate(weights.begin(),weights.end(),0);
        
        while(l<r){
            int mid = l + (r-l)/2;
            int d = 0;
            int c = 0;
            for(auto i : weights){
                 if(c+i<=mid){
                c+=i;
            }else{
                d++;
                c=i;
            }
            }
            if(c>0) d++;
            if(d<=days){
                r = mid;
            }else{
                l = mid+1;
            }
        }

        return l;
    }
};