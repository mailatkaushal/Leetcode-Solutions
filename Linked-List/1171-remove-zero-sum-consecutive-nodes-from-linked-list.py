# Time  : O(n)
# Space : O(n)

class Solution:
  def removeZeroSumSublists(self, head: Optional[ListNode]) -> Optional[ListNode]:
    dummy = ListNode(0, head)
    prefix_sum = 0
    prefix_sums = {}
    prefix_sums[prefix_sum] = dummy

    while head:
      prefix_sum += head.val
      if prefix_sum in prefix_sums:
        to_delete = prefix_sums[prefix_sum].next
        temp_sum = prefix_sum + to_delete.val
        while to_delete != head:
          del prefix_sums[temp_sum]
          to_delete = to_delete.next
          temp_sum += to_delete.val
        prefix_sums[prefix_sum].next = head.next
      else:
        prefix_sums[prefix_sum] = head
      head = head.next

    return dummy.next