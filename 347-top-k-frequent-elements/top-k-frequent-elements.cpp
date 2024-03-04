class Solution {
    struct custom {
         bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
        // Compare the first elements of the pairs
        // If they are equal, compare the second elements
        if (a.first == b.first) {
            return a.second < b.second;
        }
        return a.first < b.first;
    }
    };

public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue < pair<int, int>, vector<pair<int, int>>, custom> pq;
        unordered_map<int, int> mp;
        for (auto i : nums) {
            mp[i]++;
        }
        for(auto i : mp){
            pq.push({i.second , i.first});
        }

        vector<int> ans;

        for(int i = 0 ; i < k ; i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;

    }

}
;