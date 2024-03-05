# Time  : O(m*n)
# Space : O(1)

class Solution:
  def countBattleships(self, board: List[List[str]]) -> int:
    m, n = len(board), len(board[0])
    cnt = 1 if board[0][0] == 'X' else 0

    for i in range(1, m):
      if (board[i-1][0] != 'X' and board[i][0] == 'X'):
        cnt += 1

    for j in range(1, n):
      if (board[0][j-1] != 'X' and board[0][j] == 'X'):
        cnt += 1

    for i in range(1, m):
      for j in range(1, n):
        if board[i-1][j] != 'X' and board[i][j-1] != 'X' and board[i][j] == 'X':
          cnt += 1

    return cnt