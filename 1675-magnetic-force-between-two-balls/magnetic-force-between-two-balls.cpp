class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int n = position.size();
        int l = 0 , r = position[n-1]-position[0];


        int ans = 0;

        while(l<=r){
            int mid = l + (r-l)/2;
            int prev = position[0];
            int rem = m-1;
            int i = 1;
            while(i<n && rem >0){
                if(position[i]-prev >=mid){
                    rem--;
                    prev = position[i];
                }
                i++;
            }

            if(rem<=0){
                ans = max(ans , mid);
                l = mid+1;
            }else{
                r = mid-1;
            }

        }

        return ans;

    }
};