class Solution {
    void bk(vector<int> &nums , set<vector<int>> &st , vector<int> &s , map<int,bool> &mp){
        if(s.size()==nums.size()){
            st.insert(s);
            return;
        }

        for(int i = 0 ; i < nums.size();i++){
            if(!mp[i]){
                mp[i]=1;
            s.push_back(nums[i]);
            bk(nums,st,s,mp);
            s.pop_back();
                mp[i]=0;
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> s;
        set<vector<int>> st;
        map<int,bool> mp;
        bk(nums,st,s,mp);
        for(auto i : st){
            ans.push_back(i);
        }
        return ans;
    }
};