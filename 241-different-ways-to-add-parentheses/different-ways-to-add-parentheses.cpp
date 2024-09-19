class Solution {
    // vector<int> ans;
    int solve(int num1 , int num2 , char op){
        if(op=='+') return num1 + num2;
        else if(op=='-') return num1 - num2;
        return num1*num2;
    }
    vector<int> bt(string ex ){
        vector<int> res;
        if(ex.length() <=2){
            res.push_back(stoi(ex));
            return res;
        }
        for(int i = 0 ; i < ex.length() ;i++){
            if(ex[i]=='+' || ex[i]=='-' || ex[i]=='*'){
                auto n1 = bt(ex.substr(0,i));
                auto n2 = bt(ex.substr(i+1));
                for(auto &x : n1){
                    for(auto &y : n2){
                        res.push_back(solve(x,y,ex[i]));
                    }
                }
            }
        }
        return res;
    }

public:
    vector<int> diffWaysToCompute(string ex) {
        int n = ex.length();
        auto ans = bt(ex);
        return ans;
    }
};