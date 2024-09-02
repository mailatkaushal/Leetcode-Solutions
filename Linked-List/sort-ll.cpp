// Time  : O(nlogn)    
ListNode* merge(ListNode* a, ListNode* b) {
    ListNode* dummy=new ListNode(0);
    ListNode* d=dummy;
    while (a&&b) {
        if (a->val<=b->val) {
            d->next=a;
            a=a->next;
        }
        else {
            d->next=b;
            b=b->next;
        }
        d=d->next;
    }
    if (a) d->next=a;
    if (b) d->next=b;
    return dummy->next;
}
ListNode* sortList(ListNode* head) {
    if (head==NULL || head->next==NULL) return head;
    ListNode* fast=head;
    ListNode* slow=head;
    ListNode* prev=NULL;
    while (fast && fast->next) {
        prev=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    prev->next=NULL;
    ListNode* a=sortList(head);
    ListNode* b=sortList(slow);
    return merge(a,b);
}