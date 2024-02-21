class Solution:
  def rotate(self, matrix: List[List[int]]) -> None:
    '''
      1  2  3      7  8  9      7  4  1
      4  5  6  ->  4  5  6  ->  8  5  2
      7  8  9      1  2  3      9  6  3
    '''

    n = len(matrix)

    # reverse each row
    start, end = 0, n - 1
    while start < end:
      for i in range(n):
        matrix[start][i], matrix[end][i] = matrix[end][i], matrix[start][i]
      start += 1
      end -= 1

    # Transpose the matrix (swap non-diagonal elements)
    for i in range(n):
      for j in range(i):
        matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]