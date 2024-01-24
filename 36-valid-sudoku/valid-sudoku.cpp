class Solution {
    bool check(vector<vector<char>>& board , char c , int x , int y ){
        
        for(int i = 0 ; i< 9;i++){
            if((board[i][y]==c && i!=x) || (board[x][i]==c && i!=y) ){
                return false;
            }
        }
        
        for(int i = 3*(x/3) ; i < 3*((x/3)+1) ;i++){
            for(int j = 3*(y/3) ; j < 3*((y/3)+1) ; j++){
                if (board[i][j] == c && (i != x || j != y)) {
                return false;
            }
            }
        }
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0 ; i < board.size() ; i++){
            for(int j = 0 ; j < board.size() ; j++){
                if(board[i][j]!='.'){
                    if(!check(board , board[i][j] , i , j)){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};