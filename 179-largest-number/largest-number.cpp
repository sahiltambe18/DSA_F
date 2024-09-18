class Solution {
    struct cmp{
        bool operator()(const int &a ,const int &b){
            string aa = to_string(a);
            string bb = to_string(b);
            return aa+bb > bb+aa;
        }
    };
public:
    string largestNumber(vector<int>& nums) {
        string ans ="";
        sort(nums.begin(),nums.end() ,cmp() );
        for(auto &i : nums){
            ans+= to_string(i);
        }
        if(ans[0]=='0') return "0";
        return ans;
    }
};