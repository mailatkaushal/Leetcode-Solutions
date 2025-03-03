int singleNumber(vector<int>& A) {
    int x = 0;
    for (int a:A) x ^= a;
    return x;
}