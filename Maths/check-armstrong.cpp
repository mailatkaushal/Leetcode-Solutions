// Time  : O(n)
// Space : O(1)

bool checkArmstrong(int n){
	if (n == 0) return true;
	int cntDigit = 0;
	int num = n;
	while (num) {
		cntDigit++;
		num /= 10;
	}
	num = n;
	int sum = 0;
	while (num) {
		int digit = num % 10;
		sum += pow(digit, cntDigit);
		num /= 10;
	}
	return n == sum;
}