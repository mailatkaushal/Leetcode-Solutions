// Time  : O(nlog(logn))
// Space : O(n)
class Solution {
public:
    int countPrimes(int n) {
        int ans=0;
        vector<bool> seive(n+1,1);
        for (int i=2; i<n; ++i) {
            if (seive[i]==1) {
                ans++;
                for (int j=2*i; j<n; j+=i) {
                    seive[j]=0;
                }
            }
        }
        return ans;
    }
};