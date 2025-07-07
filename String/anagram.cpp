bool isAnagram(string s, string t) {
    vector<int> v(26);
    for (auto c:s) v[c-'a']++;
    for (auto c:t) v[c-'a']--;
    for (int i=0; i<26; ++i) {
        if (v[i]) return 0;
    }
    return 1;
}