
class Solution {
public:
    vector<string> getNextStates(const string& curr) {
        vector<string> nextStates;
        
        for (int i = 0; i < 4; ++i) {
            string temp = curr;
            
            temp[i] = (curr[i] - '0' + 1) % 10 + '0';
            nextStates.push_back(temp);

            temp[i] = (curr[i] - '0' - 1 + 10) % 10 + '0';
            nextStates.push_back(temp);
        }

        return nextStates;
    }

    int openLock(vector<string>& deadends, string target) {
        
        unordered_set<string> dead(deadends.begin(), deadends.end());
        if (dead.count("0000")) return -1; 
        
        unordered_set<string> visited;
        queue<pair<string, int>> q;
        
        
        q.push({"0000", 0});
        visited.insert("0000");
        
        while (!q.empty()) {
            auto [curr, level] = q.front();
            q.pop();
            
            if (curr == target) {
                return level;
            }
            
            
            for (const auto& next : getNextStates(curr)) {
                if (!visited.count(next) && !dead.count(next)) {
                    q.push({next, level + 1});
                    visited.insert(next);
                }
            }
        }
        
        return -1; 
    }
};
