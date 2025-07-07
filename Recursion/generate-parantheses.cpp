vector<string> ans;
void f(int open, int close, int n, string s) {
    if (open==close && open+close==2*n) {
        ans.push_back(s);
        return;
    }
    if (open<n) f(open+1,close,n,s+"(");
    if (open>close) f(open,close+1,n,s+")");
}
vector<string> generateParenthesis(int n) {
    f(0,0,n,"");
    return ans;
}