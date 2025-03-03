bool isPalindrome(int x) {
    if (x<0) return 0;
    int dup=x;
    long long rev=0;
    while (x) {
        rev=rev*10+x%10;
        x/=10;
    }
    return rev==dup;
}