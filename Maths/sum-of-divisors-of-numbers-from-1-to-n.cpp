// Time  : O(n(sqrt(x)))
// Space : O(1)

int sumOfAllDivisors(int n){
	int sum = 0;
	for (int x = 1; x <= n; ++x) {
		for (int d = 1; d*d <= x; ++d) {
			if (x % d == 0) {
				sum += d;
				if (d != x / d) 
					sum += x / d;
			}
		}
	}
	return sum;
}