/*
  Approach - 1 (Using set data structure)
  Time  : O(2n)
  Space : O(n)

  Example : "a b c a a"
  When we are at 3rd index 'a', we saw 'a' somewhere before, we delete it from set
  Now, we add 'a' at 3rd index in the set and move to 4th index.
  Now, we see that 'a' 4th index is somewhere before because it's in the set.
  But we keep deleting from set until we delete 'a' at 3rd index from the set.
  So, in worst case we'll iterate array 2 times. So, time = O(2n) 
*/

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int n = s.size();
    int len = 0;
    unordered_set<char> st;
    int l = 0, r = 0;

    while (r < n) {
      while (st.find(s[r]) != st.end()) {
        st.erase(s[l]);
        ++l;
      }
      st.insert(s[r]);
      len = max(len, r - l + 1);
      ++r;
    }

    return len;
  }
};

/*
  Approach - 1 (Using map data structure)
  Time  : O(n)
  Space : O(n)

  Instead of deleting character one by one, we can directly jump l pointer just after the last appearance of a character.
  We'll use map to store indices of character. So, in that way we don't have to move l pointer one by one.
  Now one thing to note,
  Example : "b a a b"
  When we reach at 2nd index 'a', we move l = mp['a'] + 1 = 2
  Now, When you are at 3rd index 'b', we see that we have (b, 0) in map. So, we move l = map['b'] + 1 = 1
  but we earlier had made l = 2 above. This is an issue.
  So, we do this : i = max(i, mp[ch] + 1);  // which ever is larger we make that jump for l
*/

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int n = s.size();
    int len = 0;
    unordered_map<char, int> ump;
    int l = 0, r = 0;

    while (r < n) {
      if (ump.find(s[r]) != ump.end()) {
        l = max(ump[s[r]] + 1, l);
      }
      ump[s[r]] = r;
      len = max(len, r - l + 1);
      ++r;
    }

    return len;
  }
};