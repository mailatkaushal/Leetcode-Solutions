vector<string> ans;
void f(string& s, int i, string a) {
    if (i==s.size()) {
        ans.push_back(a);
        return;
    }
    f(s,i+1,a+s[i]);
    f(s,i+1,a+" "+s[i]);
}
vector<string> permutation(string& s) {
    f(s,1,string(1,s[0]));
    sort(ans.begin(),ans.end());
    return ans;
}