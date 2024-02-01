// Time:  O(N * 4 * 3 ^ len of word - 1) ~ O(N * 3 ^ len of word) - where N, number of cells in board
// Space: O(len of word) - function call stack

class Solution {
public:
  int m, n, len;
  vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

  bool exist(vector<vector<char>>& board, string& word) {
    m = board.size();
    n = board[0].size();
    len = word.size();

    for (int i = 0; i < m; ++i) 
      for (int j = 0; j < n; ++j) 
        if (board[i][j] == word[0] && dfs(board, word, i, j, 0))
          return true;

    return false;
  }

  bool dfs(vector<vector<char>>& board, string& word, int i, int j, int k) {
    if (k == len)
      return true;
    if (i < 0 || i == m || j < 0 || j == n || board[i][j] == '$')
      return false;
    if (board[i][j] != word[k])
      return false;

    char tmp = board[i][j];
    board[i][j] = '$';

    for (auto& dir: dirs) {
      if (dfs(board, word, i + dir[0], j + dir[1], k+1))
        return true;
    }
    
    board[i][j] = tmp;
    return false;
  }
};