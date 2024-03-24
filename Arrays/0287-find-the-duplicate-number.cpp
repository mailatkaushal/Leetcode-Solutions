// Time  : O(n)
// Space : O(n)

class Solution {
public:
  int findDuplicate(vector<int>& A) {
    vector<int> v(A.size(), 0);
    for (int& a : A) {
      ++v[a];
      if (v[a] == 2)
        return a;
    }
    return -1;
  }
};

// Time  : O(n)
// Space : O(1)

class Solution:
  def findDuplicate(self, A: List[int]) -> int:
    n = len(A)
    i = 0
    while i < n:
      if A[i] < 0:
        return i
      A[i] = -A[i]
      i = abs(A[i])

// Time  : O(n)
// Space : O(1)

class Solution:
  def findDuplicate(self, A: List[int]) -> int:
    fast, slow = 0, 0
    while True:
      slow = A[slow]
      fast = A[A[fast]]
      if fast == slow:
        break
    fast = 0
    while fast != slow:
      fast = A[fast]
      slow = A[slow]
    return slow