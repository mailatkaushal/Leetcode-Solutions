Node* deleteMid(Node* head) {
    if (head->next==NULL) return NULL;
    Node* fast=head->next->next;
    Node* slow=head;
    while (fast && fast->next) {
        fast=fast->next->next;
        slow=slow->next;
    }
    slow->next=slow->next->next;
    return head;
}