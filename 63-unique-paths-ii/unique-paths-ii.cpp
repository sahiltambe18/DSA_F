class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& ob) {
        int m = ob.size();
        int n = ob[0].size();
        if(ob[0][0]==1 || ob[m-1][n-1]==1) return 0;
        bool f = 0;
        for(int i = 0 ; i < n ;i++){
            if(f) ob[0][i] = -1;
            else if(ob[0][i]==1){
                ob[0][i] = -1;
                // break;
                f = 1;
            }else{

            ob[0][i] = 1;
            }
        }

        bool flag = 0;
        for(int i = 1 ; i < m ;i++){
            if(flag) ob[i][0] = -1;
            else if(ob[i][0]==1){
                ob[i][0] = -1;
                flag =1;
                // break;
            }else{

            ob[i][0] = 1;
            } 
        }
        // for(int i = 0 ; i<n ;i++) cout<<ob[i][0]<<"\n";

        for(int i = 1; i<m ; i++){
            for(int j = 1;j<n ;j++){
                if(ob[i][j]==1){
                    ob[i][j] = -1;
                    continue;
                }
                if(ob[i-1][j]!=-1){
                    ob[i][j]+=ob[i-1][j];
                }
                if(ob[i][j-1]!=-1){
                    ob[i][j]+=ob[i][j-1];
                }
            }
        }

        return ob[m-1][n-1];

    }
};