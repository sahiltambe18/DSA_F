class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int ,int> mp;
        for(int i : arr2){
            mp[i] = 0;
        }
        vector<int> ans , excess;

        for(int j = 0 ; j < arr1.size() ; j++){
            if(mp.find(arr1[j])==mp.end()){
                excess.push_back(arr1[j]);
            }else{
                mp[arr1[j]]++;
            }
        }

        for(int i = 0 ; i < arr2.size() ; i++){
            int freq = mp[arr2[i]];
            while(freq>0){
                ans.push_back(arr2[i]);
                freq--;
            }
            // mp.erase(arr2[i]);
        }

        sort(excess.begin(),excess.end());
            for(auto i : excess){
                ans.push_back(i);
            }
        

        return ans;

    }
};