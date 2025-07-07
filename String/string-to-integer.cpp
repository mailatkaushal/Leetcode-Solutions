int myAtoi(string& s) {
    long long ans=0;
    int sign=1;
    int i=0;
    while (i<s.size() && s[i]==' ') ++i;
    if (i==s.size()) return 0;
    if (s[i]=='-') sign=-1,++i;
    else if (s[i]=='+') ++i;
    while (i<s.size() && s[i]>='0' && s[i]<='9') {
        ans=ans*10+(s[i]-'0');
        if (sign*ans>INT_MAX) return INT_MAX;
        if (sign*ans<INT_MIN) return INT_MIN;
        ++i;
    }
    return sign*ans;
}