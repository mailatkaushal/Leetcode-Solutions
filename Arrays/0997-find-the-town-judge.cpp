// Time  : O(n)
// Space : O(n)

class Solution:
  def findJudge(self, n: int, trust: List[List[int]]) -> int:
    # track who trusts how many and who is trusted by how many
    trusts = [0] * (n + 1)
    trusted_by = [0] * (n + 1)

    for t in trust:
      # t[0] trusts t[1]
      trusts[t[0]] += 1
      trusted_by[t[1]] += 1

    for i in range(1, n + 1):
      # town judge trusts nobody
      # everybody trusts the town judge (except himself)
      if trusts[i] == 0 and trusted_by[i] == n - 1:
        return i

    return -1

// Time  : O(n)
// Space : O(n)

class Solution:
  def findJudge(self, n: int, trust: List[List[int]]) -> int:
    cnt = [0] * (n + 1)

    for t in trust:
      cnt[t[0]] -= 1
      cnt[t[1]] += 1

    for i in range(1, n + 1):
      if cnt[i] == n - 1:
        return i

    return -1