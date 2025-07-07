bool isPalindrome(string& s) {
    int i=0,j=s.size()-1;
    while (i<j) {
        if (s[i]==s[j]) ++i,--j;
        else return 0;
    }
    return 1;
}