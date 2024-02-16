// Time  : O(nlogn)
// Space : O(n)

class Solution {
public:
  int findLeastNumOfUniqueInts(vector<int>& A, int& k) {
    unordered_map<int, int> ump;
    for (int& num : A) 
      ++ump[num];
      
    int n = ump.size();
    vector<int> freq(n);
    int i = 0;
    for (auto& [key, val] : ump) {
      freq[i] = val;
      ++i;
    }
    
    sort(freq.begin(), freq.end());

    int res = n;
    for (int& f : freq) {
      if (k >= f) {
        k -= f;
        --res;
        continue;
      }
      break;
    }

    return res;
  }
};

// Time  : O(nlogn)
// Space : O(n)

class Solution {
public:
  int findLeastNumOfUniqueInts(vector<int>& A, int& k) {
    unordered_map<int, int> ump;
    for (int& num : A) 
      ++ump[num];
      
    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto& [key, val] : ump) 
      pq.push(val);

    while (!pq.empty() && k >= pq.top()) {
      k -= f;
      pq.pop();
    }

    return pq.size();
  }
};

// Time  : O(n)
// Space : O(n)

class Solution {
public:
  int findLeastNumOfUniqueInts(vector<int>& A, int& k) {
    unordered_map<int, int> ump;
    for (int& num : A) 
      ++ump[num];
      
    vector<int> freq_arr(A.size() + 1);  // freq -> # of elements with that freq
    for (auto& [key, val] : ump) 
      ++freq_arr[val];

    int res = ump.size();
    for (int f = 1; f < freq_arr.size(); ++f) {
      int remove = freq_arr[f];
      if (k >= f * remove) {
        k -= f * remove;
        res -= remove;
      }
      else {
        remove = k / f;
        res -= remove;
        break;
      }
    }

    return res;
  }
};