class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        vector<int> v;
        for(auto &i:timePoints){
            int h = ((i[0]-'0')*10)+(i[1]-'0');
            int m = ((i[3]-'0')*10)+(i[4]-'0');
            v.push_back(h*60 + m);
        }
        int mini = INT_MAX;
        int size = 24*60;
        for(int i = 0 ; i < n ;i++){
            int rev = size-v[i];
            for(int j = i+1 ; j< n ;j++ ){
                int diff = abs(v[i]-v[j]);
                diff = min(diff , size-diff);
                mini = min(mini,diff);
            }
        }
        return mini;
    }
};