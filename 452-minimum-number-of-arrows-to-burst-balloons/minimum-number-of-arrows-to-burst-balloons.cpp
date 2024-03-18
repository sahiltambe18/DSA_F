class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int ans = 1;
        sort(points.begin() , points.end() , [](const auto &a , const auto &b){
            return a[1] < b[1];
        });
        int i =1 , n = points.size() , init = 0; 
        init = points[0][1];
        while(i<n){
            if(points[i][0]<= init){
                //ans++;
                i++;
            }else{
                ans++;
                init = points[i][1];
                i++;
            }
        }

        return ans;

    }
};