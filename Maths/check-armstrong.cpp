// Time  : O(n)
// Space : O(1)
class Solution {
public:
	string armstrongNumber(int n) {
		int num = n;
		int x = 0;
		while (n) {
			int y = n % 10;
			x += y*y*y;
			n /= 10;
		}
		return num == x ? "Yes" : "No";
	}
};