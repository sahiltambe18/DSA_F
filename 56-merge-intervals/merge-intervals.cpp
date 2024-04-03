class Solution {
    struct comparee{

    bool operator()(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
        }
    };
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin() , intervals.end(), comparee() );
        vector<vector<int>> ans;
        int n = intervals.size();
        for(int i = 0 ; i < n ; i++){
            int st , end ;
            st = intervals[i][0];
            end = intervals[i][1];
            while(i<n-1 && intervals[i+1][0]<=end){
                end = max(end , intervals[i+1][1]);
                i++; 
            }
            ans.push_back({st,end});
        }

        return ans;

    }
};