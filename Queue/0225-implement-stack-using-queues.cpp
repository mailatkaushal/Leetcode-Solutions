// Time  : push - O(n), pop - O(1), top - O(1), empty - O(1)
// Space : O(n)

class MyStack {
public:
  /** Initialize your data structure here. */
  queue<int> q1, q2;
  MyStack() {
  }
  
  /** Push element x onto stack. */
  void push(int x) {
    q2.push(x);
    while (!q1.empty()) {
      q2.push(q1.front());
      q1.pop();
    }
    swap(q1, q2);
  }
  
  /** Removes the element on top of the stack and returns that element. */
  int pop() {
    int x = q1.front();
    q1.pop();
    return x;
  }
  
  
  /** Get the top element. */
  int top() {
    return q1.front();
  }
  
  /** Returns whether the stack is empty. */
  bool empty() {
    return q1.empty();
  }
};

// Time  : push - O(n), pop - O(1), top - O(1), empty - O(1)
// Space : O(n)

class MyStack {
public:
  queue<int> q1;
  MyStack() {
  }
  
  void push(int x) {
    int n = q1.size();
    q1.push(x);
    while (n--) {
      q1.push(q1.front());
      q1.pop();
    }
  }
  
  int pop() {
    int x = q1.front();
    q1.pop();
    return x;
  }
  
  
  int top() {
    return q1.front();
  }
  
  bool empty() {
    return q1.empty();
  }
};

// Time  : O(1)
// Space : O(n)

class MyStack {
public:
  deque<int> dq;
  int x;

  MyStack() {
  }
  
  void push(int x) {
    dq.push_back(x);
  }
  
  int pop() {
    x = dq.back();
    dq.pop_back();
    return x;
  }
  
  int top() {
    return dq.back();
  }
  
  bool empty() {
    return dq.empty();
  }
};
