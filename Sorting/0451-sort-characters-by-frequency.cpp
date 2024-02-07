/* 
  Sort the entire string based on frequency
  Time  : O(nlogn)
  Space : O(logn)
*/

class Solution {
public:
  string frequencySort(string s) {
    vector<int> v(123);
    for (char& c : s)
      ++v[c];

    sort(s.begin(), s.end(), [&] (char& a, char& b) {
      return v[a] > v[b] || v[a] == v[b] && a < b;
    });

    return s;
  }
};

/* 
  Only sort the pairs
  Time  : O(n + klogk) - where k is the number of diff chars in input string
  Space : O(min(logn, logk))
*/

typedef pair<char, int> p;
class Solution {
public:
  string frequencySort(string s) {
    vector<p> v(123);

    for (char& c : s) {
      int freq = v[c].second;
      v[c] = {c, freq + 1};
    }

    sort(v.begin(), v.end(), [&] (p& a, p& b) {
      return a.second > b.second;
    });

    string res;

    for (int i = 0; i < 123; ++i) {
      if (v[i].second > 0) 
        res += string(v[i].second, v[i].first);  // string(freq, char)
    }

    return res;
  }
};

/*
  Bucket sort 
  Time  : O(n)
  Space : O(n)
*/

class Solution {
public:
  string frequencySort(string s) {
    int n = s.size();
    vector<int> v(123);

    for (char& c : s)
      ++v[c];

    vector<vector<char>> bucket(n+1);
    // bucket[i] -> chars that appear i times in s

    for (int i = 0; i < 123; ++i) {
      if (v[i] > 0)
        bucket[v[i]].push_back(i);
    }

    string res;

    for (int freq = n; freq >= 1; --freq) {
      for (char& c : bucket[freq]) 
        res += string(freq, c);
    }

    return res;
  }
};

/*
  Using priority queue
  Time  : O(n + klogk)
  Space : O(min(n, k))
*/

class Solution {
public:
  string frequencySort(string s) {
    vector<int> v(123);
    
    for (char& c : s) 
      ++v[c];

    priority_queue<pair<int, char>> pq;

    for (int i = 0; i < 123; ++i) {
      if (v[i] > 0)
        pq.push({v[i], i});
    }

    string res;

    while (!pq.empty()) {
      res += string(pq.top().first, pq.top().second);
      pq.pop();
    } 

    return res;
  }
};