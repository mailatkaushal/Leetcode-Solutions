# Time  : O(nlogn + n*m) - Where n is len(stalls), m is max(stalls) - min(stalls)
# Space : O(logn) - bc of sorting

bool canPlaceCows(vector<int> &stalls, int cows, int dist) {
  int n = stalls.size();
  int cnt_cows = 1;
  int prev_cow_position = stalls[0];

  for (int i = 1; i < n; ++i) {
    if (stalls[i] - prev_cow_position >= dist) {
      ++cnt_cows;
      if (cnt_cows == cows)
        return true;
      prev_cow_position = stalls[i];
    }
  }

  return false;
}

int aggressiveCows(vector<int> &stalls, int cows) {
  int n = stalls.size();
  sort(stalls.begin(), stalls.end());
  int max_dist = stalls[n-1] - stalls[0];
  
  for (int dist = 1; dist <= max_dist; ++dist) {
    if (canPlaceCows(stalls, cows, dist))
      continue;
    return dist - 1;
  }

  return max_dist;
}

# Time  : O(nlogn + nlogm) - Where n is len(stalls), m is max(stalls) - min(stalls)
# Space : O(logn) - bc of sorting

def canPlaceCows(stalls, cows, dist):
    n = len(stalls)
    cnt_cows = 1
    prev_cow_position = stalls[0]

    for i in range(1, n):
        if stalls[i] - prev_cow_position >= dist:
            cnt_cows += 1
            if cnt_cows == cows:
                return True
            prev_cow_position = stalls[i]

    return False

def aggressiveCows(stalls, cows):
    n = len(stalls)
    stalls.sort()

    lo, hi = 1, stalls[n-1] - stalls[0]

    while lo <= hi:
        dist = lo + (hi - lo) // 2
        if canPlaceCows(stalls, cows, dist):
            lo = dist + 1
        else:
            hi = dist - 1

    return hi