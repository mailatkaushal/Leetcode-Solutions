// Time: O(n)
// Space: O(n)

class Solution {
public:
  Node* flatten(Node* head) {
    if (!head)
      return head;

    stack<Node*> stk;
    Node* curr = head;

    while (curr) {
      if (!curr->child) {
        curr = curr->next;
        continue;
      }
      if (curr->next)
        stk.push(curr->next);
      curr->next = curr->child;
      curr->next->prev = curr;
      curr->child = nullptr;
      curr = curr->next;
    }

    curr = head;

    while (!stk.empty()) {
      while (curr->next)
        curr = curr->next;
      Node* tmp = stk.top();
      stk.pop();
      curr->next = tmp;
      tmp->prev = curr;
      curr = curr->next;
    }

    return head;
  }
};

// Time: O(n)
// Space: O(1)

class Solution {
public:
  Node* flatten(Node* head) {
    if (!head) 
      return head;

    Node* curr = head;

    while (curr) {
      if (!curr->child) {
        curr = curr->next;
        continue;
      }
      Node* tmp = curr->child;
      while (tmp->next) 
        tmp = tmp->next;
      tmp->next = curr->next;
      if (curr->next) 
        curr->next->prev = tmp;
      curr->next = curr->child;
      curr->next->prev = curr;
      curr->child = nullptr;
      curr = curr->next;
    }

    return head;
  }
};