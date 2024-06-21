class Solution {
public:
    int maxSatisfied(vector<int>& c, vector<int>& g, int m) {
     int ans = 0;
     int window = 0 , maxWindow = 0 , l = 0;
     int n = g.size();
     for(int i = 0 ; i < n ; i++){
        if(g[i]){
            window+=c[i];
        }else{
            ans+=c[i];
        }

        if(i-l+1>m){
            if(g[l]) window-=c[l];
            l++;
        }

        maxWindow = max(maxWindow,window);
     } 
       return ans + maxWindow;
    }
};