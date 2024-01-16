class Solution {
    bool check(vector<vector<char>>& board , int x , int y , char c){
        
        for(int i = 0 ; i< 9;i++){
            if(board[i][y]==c || board[x][i]==c){
                return false;
            }
        }
        
        for(int i = 3*(x/3) ; i < 3*((x/3)+1) ;i++){
            for(int j = 3*(y/3) ; j < 3*((y/3)+1) ; j++){
                if(board[i][j]==c){
                    return false;
                }
            }
        }
        return true;
    }

    bool bt( vector<vector<char>> &board ){
        for(int i = 0 ; i < 9 ; i++){
            for(int j = 0 ; j < 9 ; j++){
                if(board[i][j]=='.'){
                    for(char c = '1' ; c <= '9' ; c++){
                        if(check(board , i , j , c)){
                            board[i][j] = c;
                            if(bt(board)){
                                return true;
                            }
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }

            }
        }
        return true;
    }    

public:
    void solveSudoku(vector<vector<char>>& board) {
        
        bt(board);
        
    }
};