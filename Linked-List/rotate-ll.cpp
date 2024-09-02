ListNode* rotateRight(ListNode* head, int k) {
    if (head==NULL || k==0) return head;
    int len=1;
    ListNode* tail=head;
    while (tail->next) {
        len++;
        tail=tail->next;
    }
    k%=len;
    tail->next=head;
    for (int i=0; i<len-k; ++i) {
        tail=tail->next;
    }
    head=tail->next;
    tail->next=NULL;
    return head;
}