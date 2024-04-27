
struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        // Combine hashes with bitwise XOR and shift
        return hash1 ^ (hash2 << 1);  // You can use other hash combinations if desired
    }
};

class Solution {
    int minD = INT_MAX;
    unordered_map<pair<int, int>, int, hash_pair> memo; 

    int minDistance(int i, int n, int currIdx) {
        return min(abs((currIdx - i + n) % n), abs((i - currIdx + n) % n));
    }

    int solve(const unordered_map<char, vector<int>>& mp, const string& key, int keyIdx, int currIdx, int n) {
        if (keyIdx >= key.length()) {
            return 0;  
        }

        auto keyMemo = make_pair(keyIdx, currIdx);
        if (memo.count(keyMemo) > 0) {
            return memo[keyMemo];  
        }

        char c = key[keyIdx];
        int minSteps = INT_MAX;

        
        for (int pos : mp.at(c)) {
            int distance = minDistance(pos, n, currIdx);
            int steps = distance + 1 + solve(mp, key, keyIdx + 1, pos, n);
            minSteps = min(minSteps, steps);
        }

        memo[keyMemo] = minSteps;  
        return minSteps;
    }

public:
    int findRotateSteps(const string& ring, const string& key) {
        unordered_map<char, vector<int>> mp;
        int n = ring.length();

        if (n == 0) {
            return 0;  
        }

        
        for (int i = 0; i < n; i++) {
            mp[ring[i]].push_back(i);
        }

    
        minD = INT_MAX;
        memo.clear();

        int result = solve(mp, key, 0, 0, n);  
        
        return result;  
    }
};
