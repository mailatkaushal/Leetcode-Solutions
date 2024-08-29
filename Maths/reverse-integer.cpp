class Solution {
public:
    int reverse(int x) {
        long long xx=x,ans=0;
        while (xx) {
            ans=ans*10+(xx%10);
            xx/=10;
        }
        if (ans<INT_MIN || ans>INT_MAX) return 0;
        return ans;
    }
};