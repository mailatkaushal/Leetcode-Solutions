// Time  : O(steps)
// Space : O(n)

class Node {
public:
  string url;
  Node* prev;
  Node* next;
  Node(string url) : url(url), prev(nullptr), next(nullptr) {}
  Node(string url, Node* prev, Node* next) : url(url), prev(prev), next(next) {}
};

class BrowserHistory {
public:
  Node* node;
  BrowserHistory(string homepage) {
    node = new Node(homepage);
  }
  
  void visit(string url) {
    Node* newNode = new Node(url);
    node->next = newNode;
    newNode->prev = node;
    node = newNode;
  }
  
  string back(int steps) {
    while (node->prev && steps) {
      node = node->prev;
      --steps;
    }
    return node->url;
  }
  
  string forward(int steps) {
    while (node->next && steps) {
      node = node->next;
      --steps;
    }
    return node->url;
  }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */