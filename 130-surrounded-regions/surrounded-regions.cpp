class Solution {
    int di [4] = {1,-1,0,0};
    int dj [4] = {0,0,1,-1};
    void dfs(vector<vector<char>>& board , vector<vector<int>>& v , int i , int j){
        v[i][j] = 1;
        for(int x = 0 ; x < 4 ; x++){
            int ni = i + di[x];
            int nj = j + dj[x];

            if(ni>=0 && ni<board.size() && nj >=0 && nj<board[0].size() && board[ni][nj]=='O' && !v[ni][nj]){
                dfs(board , v , ni ,nj);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>>v(m,vector<int>(n,0));

        for(int i = 0 ; i < m ; i++){
            if(board[i][0]=='O'){
                dfs(board , v , i , 0);
            }
            if(board[i][n-1]=='O'){
                dfs(board , v , i , n-1);
            }
        }
        for(int i = 0 ; i < n ; i++){
            if(board[0][i]=='O'){
                dfs(board , v , 0 , i);
            }
            if(board[m-1][i]=='O'){
                dfs(board , v , m-1 , i);
            }
        }

        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(board[i][j]=='O' && !v[i][j]){
                    board[i][j] = 'X';
                }
            }
        }


    }
};