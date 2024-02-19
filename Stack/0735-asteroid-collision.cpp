// Time  : O(n)
// Space : O(n)

class Solution {
public:
  vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int> stk;

    for (int& a : asteroids) {
      while (stk.size() > 0 && a < 0 && stk.back() > 0) {
        int s = stk.back() + a;
        if (s < 0)       // a wins
          stk.pop_back();
        else if (s > 0)  // stk top wins
          a = 0;
        else {           // both exploded
          stk.pop_back();
          a = 0;
        }
      }
      
      if (a)
        stk.push_back(a);
    }

    return stk;
  }
};