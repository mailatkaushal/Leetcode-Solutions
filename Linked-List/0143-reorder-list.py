# Time  : O(n)
# Space : O(1)

class Solution:
  def reorderList(self, head: Optional[ListNode]) -> None:
    # Do not return anything, modify head in-place instead.
    fast, slow = head, head
    while fast and fast.next:
      fast = fast.next.next
      slow = slow.next

    prev = None
    while slow:
      next = slow.next
      slow.next = prev
      prev = slow
      slow = next

    lo, hi = head, prev
    while hi.next:
      lo_next = lo.next
      hi_prev = hi.next
      lo.next = hi
      hi.next = lo_next
      lo = lo_next
      hi = hi_prev