vector<string> ans;
void f(string& s, int i, string a) {
    if (i==s.size()) {
        ans.push_back(a);
        return;
    }
    if (isdigit(s[i])) f(s,i+1,a+s[i]);
    else {
        f(s,i+1,a+(char)tolower(s[i]));
        f(s,i+1,a+(char)toupper(s[i]));
    }
}
vector<string> letterCasePermutation(string& s) {
    f(s,0,"");
    return ans;
}