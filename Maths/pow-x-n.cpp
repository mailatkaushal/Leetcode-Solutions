class Solution {
public:
    double myPow(double x, int n) {
        if (n<0) x=1/x;
        long long nn=n;
        double ans=1;
        while (nn) {
            if (nn%2==0) {
                x*=x;
                nn/=2;
            }
            else {
                ans*=x;
                x*=x;
                nn/=2;
            }
        }
        return ans;
    }
};