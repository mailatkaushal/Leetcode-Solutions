# Time  : O(4*m*n)
# Space : O(1)

class Solution {
public:
  vector<int> findPeakGrid(vector<vector<int>>& M) {
    int m = M.size(), n = M[0].size();

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        int u = i == 0 ? -1 : M[i-1][j];
        int d = i == m-1 ? -1 : M[i+1][j];
        int l = j == 0 ? -1 : M[i][j-1];
        int r = j == n-1 ? -1 : M[i][j+1];
        if (u < M[i][j] && M[i][j] > d && l < M[i][j] && M[i][j] > r)
          return {i, j};
      }
    }

    return {-1, -1};
  }
};

# Time  : O(m*n)
# Space : O(1)

class Solution:
  def findPeakGrid(self, M: List[List[int]]) -> List[int]:
    m, n = len(M), len(M[0])
    r, c = 0, 0
    
    for i in range(m):
      for j in range(n):
        if M[i][j] > M[r][c]:
          r, c = i, j

    return [r, c]

# Time  : O(m*n)
# Space : O(1)

class Solution:
  def findPeakGrid(self, M: List[List[int]]) -> List[int]:
    m, n = len(M), len(M[0])
    i, j = 0, 0

    while i < m and j < n:
      if i > 0 and M[i-1][j] > M[i][j]:
        i -= 1
      elif j > 0 and M[i][j-1] > M[i][j]:
        j -= 1
      elif i < m-1 and M[i+1][j] > M[i][j]:
        i += 1
      elif j < n-1 and M[i][j+1] > M[i][j]:
        j += 1
      else:
        return [i,j]

# Time  : O(mlogn)
# Space : O(1)

class Solution:
  def findPeakGrid(self, M: List[List[int]]) -> List[int]:
    m, n = len(M), len(M[0])
    lo, hi = 0, n - 1

    while lo <= hi:
      midCol = lo + (hi - lo) // 2
      maxRow = 0
      for i in range(m):
        if M[i][midCol] > M[maxRow][midCol]:
          maxRow = i
      left = -1 if midCol == 0 else M[maxRow][midCol-1]
      right = -1 if midCol == n-1 else M[maxRow][midCol+1]

      if left < M[maxRow][midCol] > right:
        return [maxRow, midCol]
      elif left > M[maxRow][midCol]:
        hi = midCol - 1
      else:
        lo = midCol + 1