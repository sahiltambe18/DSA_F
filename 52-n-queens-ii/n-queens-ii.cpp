class Solution {

    bool isSafe(vector<vector<int>> &bord , int x , int y ){
        int n = bord.size();
       
       for (int i = 0; i < x; ++i) {
            if (bord[i][y])
                return false;
        }
        //upper left diagonal
        for (int i = x, j = y; i >= 0 && j >= 0; --i, --j) {
            if (bord[i][j])
                return false;
        }
        // upper right diagonal
        for (int i = x, j = y; i >= 0 && j < n; --i, ++j) {
            if (bord[i][j])
                return false;
        }
               
        return true;
    }
    int count = 0;
    void bk(vector<vector<int>> &bord , int k){
       int n = bord.size();
        if(k==n){
            count++;
            return;
        }
        for(int i = 0 ; i < n;++i){
            if(isSafe(bord,k,i )){
                bord[k][i] = 1;
                bk(bord,k+1);
                bord[k][i] = 0;
            }
        }
    }

public:
    int totalNQueens(int n) {
        if (n < 1) return 0; // Edge case
        vector<vector<int>> bord(n, vector<int>(n, 0));
        bk(bord, 0);
        return count;
    }
};