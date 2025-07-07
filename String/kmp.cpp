vector<int> search(string& pat, string& s) {
    int m=pat.size();
    vector<int> lps(m);
    int len=0;
    int i=1;
    while (i<m) {
        if (pat[len]==pat[i]) {
            ++len;
            lps[i++]=len;
        }
        else if (len!=0) len=lps[len-1];
        else ++i;
    }
    int n=s.size();
    i=0;
    int j=0;
    vector<int> ans;
    while (i<n) {
        if (s[i]==pat[j]) ++i,++j;
        if (j==m) ans.push_back(i-j),j=lps[j-1];
        else if (s[i]!=pat[j]) {
            if (j==0) ++i;
            else j=lps[j-1];
        }
    }
    return ans;
}