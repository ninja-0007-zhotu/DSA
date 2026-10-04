class Solution {
public:
    bool solve(int i, int j, int k, const string& word,
               vector<vector<char>>& board) {
        if (k == word.length()) {
            return true;
        }
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() ||
            board[i][j] != word[k]) {
            return false;
        }
        board[i][j] = '.';
        bool ans = solve(i + 1, j, k + 1, word, board) ||
                   solve(i - 1, j, k + 1, word, board) ||
                   solve(i, j + 1, k + 1, word, board) ||
                   solve(i, j - 1, k + 1, word, board);
        board[i][j] = word[k];
        return ans;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (solve(i, j, 0, word, board)) {
                    return true;
                }
            }
        }
        return false;
    }
};