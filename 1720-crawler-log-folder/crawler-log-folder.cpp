class Solution {
public:
    int minOperations(vector<string>& logs) {
        int n = 0;
        for(auto i : logs){
            if(i=="../"){
                if(n>0) n--;

            }else if(i!="./"){
                n++;
            }
        }
        return n;
    }
};