class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long ans = 0;
        long long sum = accumulate(skill.begin(),skill.end(), 0LL);
        int n = skill.size();
        if((sum*2)%n!=0) return -1;
        sum = (sum*2)/n;
        cout<<sum;
        unordered_map<int,int>mp;
        for(auto &i : skill){
            if(i>sum) return -1;
            else if(mp.find(sum-i)!=mp.end()){
                ans+= i* (sum-i);
                if(mp[sum-i]==1){
                    mp.erase(sum-i);
                }else{
                    mp[sum-i]--;
                }
            }else{
                mp[i]++;
            }
        }
        if(!mp.empty()) return -1;
        return ans;
    }
};