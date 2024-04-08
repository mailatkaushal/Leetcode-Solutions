// Time  : O(n)
// Space : O(1)

class Solution{
public:
  Node* divide(int N, Node* head){
    Node* odd = new Node(1);
    Node* even = new Node(2);
    Node* o = odd;
    Node* e = even;
    while (head) {
      if (head->data % 2 == 1) {
        o->next = head;
        o = o->next;
      }
      else {
        e->next = head;
        e = e->next;
      }
      head = head->next;
    }
    o->next = NULL;
    e->next = NULL;
    e->next = odd->next;
    return even->next;
  }
};