class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions,
                                      vector<int>& healths, string directions) {
        vector<vector<int>> robots;
        int n = healths.size();
        for (int i = 0; i < n; i++) {
            robots.push_back(
                {positions[i], directions[i] == 'L' ? 1 : 0, healths[i], i});
        }
        sort(robots.begin(), robots.end());

        vector<vector<int>> st;
        int i = 0;
        // idx d h
        while (i < n) {
            bool flag = 0;
            while (i < n && !st.empty() && st.back()[1]==0 && robots[i][1]==1) {
                vector<int> top = st.back();
                if (top[2] > robots[i][2]) {
                    st.back()[2] -= 1;
                    i++;

                } else if (top[2] < robots[i][2]) {
                    st.pop_back();
                    robots[i][2] -= 1;

                } else {
                    st.pop_back();
                    i++;
                }
                flag = 1;
            }

            if (!flag) {
                
                st.push_back({robots[i][3], robots[i][1], robots[i][2]});
                i++;
            }
        }

        sort(st.begin(), st.end());
        vector<int> v;

        
        for (auto j : st) {
            v.push_back(j[2]);
        }

        return v;
    }
};