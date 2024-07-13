class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<vector<int>> robots;
        int n = healths.size();
        
        // Combine positions, healths, and directions into a single vector
        for (int i = 0; i < n; i++) {
            robots.push_back({positions[i], directions[i] == 'L' ? 1 : 0, healths[i], i});
        }
        
        // Sort robots by their positions
        sort(robots.begin(), robots.end());
        
        vector<vector<int>> st; // Stack to maintain robots
        int i = 0;
        
        while (i < n) {
            if (!st.empty() && st.back()[1] == 0 && robots[i][1] == 1) {
                // Collision detected: one robot moving right (st.back()) 
                vector<int> top = st.back();
                
                if (top[2] > robots[i][2]) {
                    // The top robot survives with reduced health
                    st.back()[2] -= 1;
                    i++; // Move to the next robot in the list
                } else if (top[2] < robots[i][2]) {
                    // The current robot survives with reduced health
                    robots[i][2] -= 1;
                    st.pop_back();
                } else {
                    // Both robots have the same health and destroy each other
                    st.pop_back();
                    i++;
                }
            } else {
                // If there was no collision, or after handling the collision
                st.push_back({robots[i][3], robots[i][1], robots[i][2]});
                i++;
            }
        }
        
        // Sort the stack based on the original indices of robots
        sort(st.begin(), st.end());
        vector<int> v;
        
        // Extract the healths of surviving robots
        for (auto j : st) {
            v.push_back(j[2]);
        }
        
        return v;
    }
};
