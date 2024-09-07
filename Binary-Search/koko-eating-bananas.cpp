// binary search on answers
int minEatingSpeed(vector<int>& piles, int h) {
    int lo=1,hi=*max_element(piles.begin(),piles.end());
    while (lo<=hi) {
        int speed=(lo+hi)>>1;
        long long hours=0;
        for (int p:piles) {
            hours+=ceil((double)p/speed);
        }
        if (hours>h) lo=speed+1;
        else hi=speed-1;
    }
    return lo;
}