ListNode* reverseList(ListNode* head) {
    ListNode* p=NULL;
    ListNode* c=head;
    while (c) {
        ListNode* next=c->next;
        c->next=p;
        p=c;
        c=next;
    }
    return p;
}