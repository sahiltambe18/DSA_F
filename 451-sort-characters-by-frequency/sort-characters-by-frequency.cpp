class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> umap;
        for(auto i : s){
            umap[i]++; // freq
        }
        
        priority_queue<pair<int,char>> pq;
        for(auto i : umap){
            pq.push(make_pair(i.second,i.first)); // priority to higher freq
        }
        string ans ="";
        while(!pq.empty()){
            int n = pq.top().first; // top-> highest req
            while(n>0){
                ans+=pq.top().second;
                n--;
            }
            pq.pop();//pop top
        }
        return ans;
    }
};