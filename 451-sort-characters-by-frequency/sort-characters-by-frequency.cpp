class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> umap;
        for(auto i : s){
            umap[i]++;
        }
        sort(s.begin(),s.end() , [&](char a , char b){
            if(umap[a]!=umap[b]) return umap[a]>umap[b];
            else return a<b;
        });
        return s;
    }
};