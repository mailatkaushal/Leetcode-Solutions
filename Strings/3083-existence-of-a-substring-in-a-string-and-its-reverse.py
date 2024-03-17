# Time  : O(n^2)
# SPace : O(n)

class Solution:
  def isSubstringPresent(self, s: str) -> bool:
    n = len(s)
    
    reverse = ""
    for i in range(n-1, -1, -1):
      reverse += s[i]
      
    for i in range(1, n):
      for j in range(1, n):
        if reverse[i-1] == s[j-1] and reverse[i] == s[j]:
          return True
        
    return False