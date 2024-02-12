class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> umap;
        int res = 0 ,l = 0 , total = 0;
        for(int i = 0 ; i < fruits.size() ; i++){
            umap[fruits[i]]++;
            total++;
            while(umap.size()>2){
                umap[fruits[l]]--;
                total--;
                if(umap[fruits[l]]==0){
                    umap.erase(fruits[l]);
                }
                l++;
            }
            res = max(res,total);
        }
        return res;
    }
};