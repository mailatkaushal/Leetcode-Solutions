bool hasCycle(ListNode* head) {
    ListNode* fast=head;
    ListNode* slow=head;
    while (fast && fast->next) {
        fast=fast->next->next;
        slow=slow->next;
        if (fast==slow) return 1;
    } 
    return 0;
}