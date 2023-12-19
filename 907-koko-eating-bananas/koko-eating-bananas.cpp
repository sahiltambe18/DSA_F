class Solution {
    bool ispossible(vector<int>& piles, int h , int speed){
        int time = 0;
        for(auto i : piles){
            time += (i+ speed-1) / speed;
            if(time>h) return false;
        }
        return (time<=h);
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
         cout.tie(0);
        cin.tie(0);
        ios_base::sync_with_stdio(0);

        int l = 1 , r = *max_element(piles.begin(), piles.end());
        while(l<r){
            int mid = l + (r-l)/2;
            if(ispossible(piles,h,mid)){
                r = mid;
            }else{
                l = mid+1;
            }
        }
        return l; 
    }
};