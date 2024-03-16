# Time  : O(n)
# Space : O(1)

class Solution:
  def sumOfEncryptedInt(self, A: List[int]) -> int:
    sum = 0
    
    def encrypt(n):
      ma = 1
      digits = 0
      while n:
        digits += 1
        digit = n % 10
        ma = max(ma, digit)
        n //= 10
      ret = 0
      for i in range(digits):
        ret = ret * 10 + ma
      return ret
    
    for n in A:
      sum += encrypt(n)
      
    return sum