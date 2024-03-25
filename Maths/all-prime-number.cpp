// Time  : O(n*sqrt(n))
// Space : O(1)

bool isPrime(int n) {
	if (n == 1)
		return false;
	for (int i = 2; i*i <= n; ++i) {
		if (n % i == 0)
			return false;
	}
	return true;
}

int main() {
    int n;
    cin>>n;

    for (int i = 2; i <= n; ++i) {
      if (isPrime(i))
        cout<<i<<endl;
    }
    return 0;
}

// Time  : O(n + nlog(logn) + n)
// Space : O(n)

int main() {
  int n;
  cin>>n;
  vector<bool> prime(n+1, 1);
  for (int i = 2; i*i <= n; ++i) {
    if (prime[i] == 1) {
      for (int j = i*i; j <= n; j += i) 
        prime[j] = 0;
    }
  }
  for (int i = 2; i <= n; ++i) 
    if (prime[i])
      cout<<i<<endl;
  return 0;
}