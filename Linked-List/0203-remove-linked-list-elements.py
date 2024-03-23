# Time  : O(n)
# Space : O(1)

class Solution:
  def removeElements(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
    dummy = ListNode(0, head)
    prev = dummy
    while head:
      if head.val == val:
        prev.next = head.next
      else:
        prev = head
      head = head.next
    return dummy.next