# Time  : O(n)
# Space : O(1)

class Solution:
  def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
    dummy = ListNode(0, head)
    prev = dummy
    curr = head
    while curr and curr.next:
      second = curr.next
      nextPairStart = second.next
      second.next = curr
      curr.next = nextPairStart
      prev.next = second
      prev = curr
      curr = nextPairStart
    return dummy.next