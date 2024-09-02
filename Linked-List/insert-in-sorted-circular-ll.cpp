Node* sortedInsert(Node* head, int data) {
    Node* x=new Node(data);
    if (head==NULL) {
        x->next=x;
        head=x;
    }
    else if (data<=head->data) {
        Node* tail=head;
        while (tail->next!=head) {
            tail=tail->next;
        }
        x->next=head;
        tail->next=x;
        head=x;
    }
    else {
        Node* i=head;
        while (i->next!=head && data>i->next->data) {
            i=i->next;
        }
        x->next=i->next;
        i->next=x;
    }
    return head;
}