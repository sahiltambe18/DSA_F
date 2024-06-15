class Solution {
    struct Compare {
        bool operator()(const std::pair<int, int>& a,
                        const std::pair<int, int>& b) {
            if (a.first == b.first) {
                return a.second < b.second;
            }
            return a.first > b.first;
        }
    };

public:
    int findMaximizedCapital(int k, int w, vector<int>& profits,vector<int>& capital) {
        
        priority_queue<int> maxQ;
        int n = capital.size();
        vector<pair<int,int>> v(n);
        for(int i = 0 ; i < n ; i++){
            v[i] = {capital[i],profits[i]};
        }

        sort(v.begin(),v.end());
        int i = 0;
        for( ;  k>0 ; k-- ){

            while(i<n && v[i].first<=w){
                maxQ.push(v[i].second);
                i++;
            }

            if(maxQ.size()==0){
                break;
            }

            w+=maxQ.top();
            maxQ.pop();

        }
        

        return w;
    }
};