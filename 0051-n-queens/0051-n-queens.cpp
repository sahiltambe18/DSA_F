class Solution {
public:
    bool isSafe(vector<string>&bord ,int n , int x , int y){
        
        for(int i = 0 ; i<n ; i++){
            if(bord[x][i]=='Q' || bord[i][y]=='Q'){
                return false;
            }
        }
        int i = x;
        int j = y;
        while(i>=0 && j>=0){
            if(bord[i][j]=='Q'){
                return false;
            }
            i--;
            j--;
        }
         i = x;
         j = y;
        while(j>=0 && i<n){
            if(bord[i][j]=='Q'){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void nQueen(int n , vector<string>&bord ,int col , vector<vector<string>> &sols ){
        if (col == n ) {
        sols.push_back(bord);
        return;
    }
        for(int i = 0;i < n ;i++){
            if(isSafe(bord,n,i,col)){
                bord[i][col] = 'Q';
                nQueen(n,bord,col+1,sols);
                bord[i][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> sols;
        vector<string> bord(n, string(n, '.')); 
        nQueen(n,bord,0,sols);
        return sols;
    }
};