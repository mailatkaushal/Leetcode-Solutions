// Time  : O(n)
// Space : O(1)

bool isPrime(int n) {
	int divisors = 0;
	for (int i = 1; i <= n; ++i) 
		if (n % i == 0) 
			++divisors;

	return divisors == 2;
}

// Time  : O(sqrt(n))
// Space : O(1)

bool isPrime(int n) {
	int divisors = 0;
	for (int i = 1; i*i <= n; ++i) {
		if (n % i == 0) {
			++divisors;
			if (i != n / i)
				++divisors;
		}
	}
	return divisors == 2;
}