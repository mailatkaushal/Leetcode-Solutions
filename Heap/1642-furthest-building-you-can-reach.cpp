// Time  : O(nlogn)
// Space : O(n)

class Solution {
public:
  int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
    int n = heights.size();
    priority_queue<int> pq;  // max-heap

    int i;
    for (i = 0; i < n-1; ++i) {
      int diff = heights[i + 1] - heights[i];

      if (diff <= 0)
        continue;

      if (bricks >= diff) {
        bricks -= diff;
        pq.push(diff);  // used diff bricks here
      }
      else if (ladders > 0) {
        if (!pq.empty()) {
          int max_bricks_past = pq.top();
          if (max_bricks_past > diff) {
            // used unneccasrily huge # of bricks in past. get it back
            bricks += max_bricks_past;
            pq.pop();
            bricks -= diff;
            pq.push(diff);
          }
        }
        --ladders;  // either used in past or present
      }
      else 
        break;
    }

    return i;
  }
};