void removeLoop(Node* head) {
    Node* fast=head;
    Node* slow=head;
    while (fast && fast->next) {
        fast=fast->next->next;
        slow=slow->next;
        if (fast==slow) {
            if (fast==head) {
                slow=slow->next;
                while (slow->next!=head) {
                    slow=slow->next;
                }
                slow->next=NULL;
                break;
            }
            fast=head;
            while (fast->next!=slow->next) {
                fast=fast->next;
                slow=slow->next;
            }
            slow->next=NULL;
            break;
        }
    }
}