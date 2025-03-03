int reverse(int x) {
    long long rev=0;
    while (x) {
        rev=rev*10+x%10;
        x/=10;
    }
    if (rev<INT_MIN || rev>INT_MAX) return 0;
    return rev;
}