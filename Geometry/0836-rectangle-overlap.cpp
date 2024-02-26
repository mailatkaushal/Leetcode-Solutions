class Solution:
  def isRectangleOverlap(self, rec1: List[int], rec2: List[int]) -> bool:
    l1, b1, r1, t1 = rec1
    l2, b2, r2, t2 = rec2
    
    return l1 < r2 and b1 < t2 and l2 < r1 and b2 < t1

'''
  [l1,b1,r1,t1] -> rec1
  [l2,b2,r2,t2] -> rec2

               ______________ r2,t2
              |              |
       _______|______ r1,t1  |
      |       |______|_______|
      |     l2,b2    |
      |______________|
    l1,b1

  Now, any rectangle overlap will satisfy 4 conditions
  
  Condition 1:
    rec2 is on left of rec1 (l1 < r2)

                   r2,t2      r1,t1
       _________________________ 
      |          |   |          |
      |          |   |          |
      |__________|___|__________|
    l2,b2      l1,b1
  
  Condition 2:
    rec2 is on bottom of rec1 (b1 < t2)

          ______________ r1,t1 
         |              |
         |______________|r2,t2
    l1,r1|______________|
         |              |
         |______________|
    l2,b2

  Condition 3:
    rec1 is on left of rec2 (l2 < r1)

                   r1,t1      r2,t2
       _________________________ 
      |          |   |          |
      |          |   |          |
      |__________|___|__________|
    l1,b1      l2,b2

  Condition 4:
    rec1 is on bottom of rec2 (b2 < t1)

          ______________ r2,t2
         |              |
         |______________|r1,t1
    l2,r2|______________|
         |              |
         |______________|
    l1,b1

  :-)

'''

class Solution:
  def isRectangleOverlap(self, rec1: List[int], rec2: List[int]) -> bool:
    l1, b1, r1, t1 = rec1
    l2, b2, r2, t2 = rec2
  
    l = max(l1, l2)
    r = min(r1, r2)
    b = max(b1, b2)
    t = min(t1, t2)
    
    return r - l > 0 and t - b > 0

'''
  [l1,b1,r1,t1] -> rec1
  [l2,b2,r2,t2] -> rec2

               ______________ r2,t2
              |              |
       _______|______ r1,t1  |
      |       |______|_______|
      |     l2,b2    |
      |______________|
    l1,b1

  find the edges of overlaped area
  
  l = max(l1, l2)
  r = min(r1, r2)
  b = max(b1, b2)
  t = min(t1, t2)

  If both edges are positive, it means that the overlap has positive area

  :-)

'''