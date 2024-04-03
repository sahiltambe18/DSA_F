class Solution {
    struct cmp{
        bool operator()(const vector<int> &a , const vector<int> &b){
            //if(a[0]==b[0]){
                return a[1]<b[1];
            // }else{
            //     return a[0]<b[0];
            // }
        }
    };
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int cnt = 0 , n = intervals.size();
        sort(intervals.begin(), intervals.end() , cmp());
        vector<int> interval = intervals[0];
        for(int i = 1 ; i < n ; i++){
            if(interval[1]>intervals[i][0]){
                cnt++;
                intervals[i] = interval;
            }else{
                interval = intervals[i];
            }
        }

        return cnt;

    }
};