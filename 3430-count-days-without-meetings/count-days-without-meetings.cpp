class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        if(meetings.empty()) return  days;
        sort(meetings.begin(),meetings.end());
        int n = meetings.size();
        vector<vector<int>> merge;
        merge.push_back(meetings[0]);

        for(int i = 1 ; i < n ; i++){
            if(merge.back()[1]>=meetings[i][0]){
                merge.back()[1] = max(merge.back()[1],meetings[i][1]);
            }else{
                merge.push_back(meetings[i]);
            }
        }

        int tot = merge[0][0]-1;

        for(int i = 0 ; i < merge.size()-1 ; i++){
            // vector<int> a = merge[i] , b = merge[i+1];

            tot+= merge[i+1][0]-merge[i][1]-1;
        }
        tot+= days-merge.back()[1];
        return tot;
    }

};