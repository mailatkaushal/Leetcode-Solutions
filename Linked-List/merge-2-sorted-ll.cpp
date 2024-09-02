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