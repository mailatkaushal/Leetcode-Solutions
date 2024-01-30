// Time  : push - O(1), pop - Amortized O(1), peek - O(1), empty - O(1)
// Space : O(n)

class MyQueue {
public:
  stack<int> s1, s2;
  int peekEl = -1;

  /** Initialize your data structure here. */
  MyQueue() {
    
  }
  
  /** Push element x to the back of queue. */
  void push(int x) {
    if (s1.empty())
      peekEl = x;
    s1.push(x);
  }
  
  /** Removes the element from in front of queue and returns that element. */
  int pop() {
    // O(n) only when s2 is empty
    if (s2.empty()) {
      // s1 -> s2
      while (!s1.empty()) {
        s2.push(s1.top());
        s1.pop();
      }
    }

    int x = s2.top();
    s2.pop();
    return x;
  }
  
  /** Get the front element. */
  int peek() {
    return s2.empty() ? peekEl : s2.top();
  }
  
  /** Returns whether the queue is empty. */
  bool empty() {
    return s1.empty() && s2.empty();
  }
};