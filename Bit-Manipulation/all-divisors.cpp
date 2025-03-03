vector<int> allDivisors(int n) {
    vector<int> ans;
    for (int i=1; i*i<=n; ++i) {
        if (n%i==0) {
            ans.push_back(i);
            if (i!=n/i) ans.push_back(n/i);
        }
    }
    return ans;
}