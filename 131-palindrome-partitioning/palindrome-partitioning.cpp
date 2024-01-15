class Solution {
    bool check(string s , int i , int j){
        while(i<=j){
            if(s[i++]!=s[j--]){
                return false;
            }
        }
        return true;
    }

    void bk(vector<vector<string>> &ans,string s , vector<string> &part,int ind ){
        if(s.size()==ind){
            ans.push_back(part);
            return;
        }

        for(int j = ind ; j <s.size();j++){
            if(check(s,ind,j)){
                part.push_back(s.substr(ind,j-ind+1));
                bk(ans,s,part,j+1);
                part.pop_back();
            }
        }
    }

   

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> part;

        bk(ans , s,part,0);
        return ans;
    }
};