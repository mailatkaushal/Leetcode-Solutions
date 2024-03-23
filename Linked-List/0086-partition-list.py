# Time  : O(n)
# Space : O(n)

class Solution:
  def partition(self, head: Optional[ListNode], x: int) -> Optional[ListNode]:
    A = ListNode(0)
    B = ListNode(0)
    a = A
    b = B
    while head:
      if head.val < x:
        a.next = head
        a = a.next
      else:
        b.next = head
        b = b.next
      head = head.next
    a.next = B.next
    b.next = None
    return A.next