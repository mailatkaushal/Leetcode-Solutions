# Time  : O(n)
# Space : O(n)

class Solution:
  def decode(self, encoded: List[int], first: int) -> List[int]:
    '''
      arr -> encoded
      arr[i] ^ arr[i+1] = encoded[i]
               to find

      a xor b = c
      (a xor b) xor a = c xor a
      (a xor a) xor b = c xor a
      0 xor b = c xor a
      b = c xor a

      arr[i+1] = encoded[i] ^ arr[i]

    '''

    arr = [0] * (len(encoded) + 1)
    arr[0] = first

    for i in range(len(encoded)):
      arr[i+1] = encoded[i] ^ arr[i]

    return arr