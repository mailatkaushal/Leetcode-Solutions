# Time  : O(n^2)
# Space : O(n)

class Solution:
  def getRow(self, rowIndex: int) -> List[int]:
    pre = [1]

    for i in range(1, rowIndex + 1):
      row = [1] * (i + 1)
      for j in range(1, i):
        row[j] = pre[j-1] + pre[j]
      pre = row

    return pre