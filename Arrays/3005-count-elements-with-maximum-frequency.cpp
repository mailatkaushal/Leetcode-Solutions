// 2 pass
// Time  : O(n)
// Space : O(1)

class Solution {
public:
  int maxFrequencyElements(vector<int>& A) {
    vector<int> freq(101);
    int max_freq = 0;
    for (int & n : A)
      max_freq = max(max_freq, ++freq[n]);
    
    int total = 0;
    for (int& f : freq) 
      if (f == max_freq)
        total += f;

    return total;
  }
};

// 1 pass
// Time  : O(n)
// Space : O(1)

class Solution {
public:
  int maxFrequencyElements(vector<int>& A) {
    vector<int> freq(101);
    int max_freq = 0;
    int total = 0;

    for (int& n : A) {
      int f = ++freq[n];
      if (f == max_freq)
        total += f;
      else if (f > max_freq) {
        max_freq = f;
        total = f;
      }
    }

    return total;
  }
};