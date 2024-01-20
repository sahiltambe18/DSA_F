class Solution {
    bool flag;
    
    void check(vector<vector<char>>& board, vector<vector<bool>>& v, string word, int n, int x, int y) {
        if (x >= board.size() || y >= board[0].size() || x < 0 || y < 0 || v[x][y] == true) {
            return;
        }
        if (n == word.length() - 1 && word[n] == board[x][y]) {
            flag = true;
            return;
        }
        if (n >= word.length()) return;

        if (word[n] == board[x][y]) {
            v[x][y] = true;
            check(board, v, word, n + 1, x, y + 1);
            check(board, v, word, n + 1, x + 1, y);
            check(board, v, word, n + 1, x, y - 1);
            check(board, v, word, n + 1, x - 1, y);
            v[x][y] = false;  //  backtrack
        }
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> v(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                flag = false;  
                check(board, v, word, 0, i, j);
                if (flag) return true;
            }
        }
        return false;
    }
};
