double myPow(double x, int n) {
    if (n<0) x=1/x;
    double ans=1;
    while (n) {
        if (n%2==0) {
            x*=x;
            n/=2;
        }
        else {
            ans*=x;
            x*=x;
            n/=2;
        }
    }
    return ans;
}