class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage,int k) {
        int n = wage.size();
        vector<pair<double, int>> ratios(n);
        for (int i = 0; i < n; i++) {
            ratios[i] = make_pair(static_cast<double>(wage[i]) / quality[i], quality[i]);

        //    ratios[i] = make_pair((double)(wage[i] / quality[i]), quality[i]);
        }

        sort(ratios.begin(), ratios.end());

        priority_queue<int> pq;
        double min_cost = numeric_limits<double>::max();
        int sum = 0;

        for (auto i : ratios) {
            double ratio = i.first;
            int quali = i.second;

            sum+= quali;
            pq.push(quali);

            if(pq.size()>k){
                sum-=pq.top();
                pq.pop();
            }

            if(pq.size()==k){
                min_cost = min(min_cost , (double)(sum*ratio));
            }
        }
        return min_cost;
    }
};