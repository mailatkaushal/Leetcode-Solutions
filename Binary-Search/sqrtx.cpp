int mySqrt(int x) {
    long long lo = 0;
    long long hi = x;
    while (lo<=hi) {
        long long mid =(lo+hi)>>1;
        if (mid*mid<=x) lo=mid+1;
        else hi=mid-1;
    }
    return hi;
}