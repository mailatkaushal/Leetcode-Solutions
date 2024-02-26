// Time  : O(1)
// Space : O(1)

class Solution {
public:
  bool checkOverlap(int radius, int xc, int yc, int x1, int y1, int x2, int y2) {
    int nearestX = xc < x1 ? x1 : (xc > x2 ? x2 : xc);
    int nearestY = yc < y1 ? y1 : (yc > y2 ? y2 : yc);
    int distX = nearestX - xc;
    int distY = nearestY - yc;
    return distX*distX + distY*distY <= radius*radius;
  }
};