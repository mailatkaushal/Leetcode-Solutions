int ans=0;
void toh(int n, int from, int to, int aux) {
    if (n==1) {
        // cout<<"move disk "<<n<<" from rod "<<from<<" to "<<to<<endl;
        ans++;
        return;
    }
    toh(n-1,from,aux,to);
    // cout<<"move disk "<<n<<" from rod "<<from<<" to "<<to<<endl;
    ans++;
    toh(n-1,aux,to,from);
}
int towerOfHanoi(int n, int from, int to, int aux) {
    if (n==0) return 0;
    toh(n,from,to,aux);
    return ans;
}