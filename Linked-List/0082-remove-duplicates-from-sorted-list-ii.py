# Time  : O(n)
# Space : O(1)

class Solution:
  def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
    dummy = ListNode(0, head)
    prev, curr = dummy, head

    while curr:
      itr = curr
      while itr.next and itr.next.val == curr.val:
        itr = itr.next
      if curr == itr:  # unique
        prev = curr
        curr = curr.next
      else:  # duplicates
        prev.next = itr.next
        curr = itr.next
    
    return dummy.next