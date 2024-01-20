class Solution {
    bool check(vector<vector<char>>& board, string &word, int n, int x, int y) {
        if (x >= board.size() || y >= board[0].size() || x < 0 || y < 0 || board[x][y]!=word[n]) {
            return false;
        }
        if (n == word.length()-1) return true;
        
        
        char og = board[x][y]; 
        board[x][y] = '#';

        bool res = check(board, word, n + 1, x + 1, y) || 
                     check(board, word, n + 1, x - 1, y) || 
                     check(board, word, n + 1, x, y + 1) || 
                     check(board, word, n + 1, x, y - 1);
        board[x][y] = og;
        
        return res;
    }



public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if(check(board, word, 0, i, j)){
                    return true;
                }
            }
        }
        return false;
    }
};
