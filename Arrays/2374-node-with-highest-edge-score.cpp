// Time  : O(n)
// Space : O(n)

class Solution:
  def edgeScore(self, edges: List[int]) -> int:
    n = len(edges)
    score = [0] * n  # score[i] -> sum of all nodes that have an edge pointing to i

    for i in range(n):
      score[edges[i]] += i

    node = -1
    max_score = -1

    for i in range(n):
      if score[i] > max_score:
        max_score = score[i]
        node = i

    return node