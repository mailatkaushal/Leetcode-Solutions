// Time  : O(k*n + n)
// Space : O(n-1)

double minimiseMaxDistance(vector<int>& A, int k){
	int n = A.size();
	vector<int> between(n - 1);

	for (int gs = 1; gs <= k; ++gs) {
		double max_section = -1;
		int max_idx = -1;

		for (int i = 0; i < n - 1; ++i) {
			double diff = A[i+1] - A[i];
			double section = diff / (between[i] + 1);
			if (section > max_section) {
				max_section = section;
				max_idx = i;
			} 
		}

		++between[max_idx];
	}

	double max_section = -1;

	for (int i = 0; i < n - 1; ++i) {
		double diff = A[i+1] - A[i];
		double section = (double)(diff) / (between[i] + 1);
		max_section = max(max_section, section);
	}

	return max_section;
}

// Time  : O(nlogn + klogn)
// Space : O(n-1)

#include <queue> 
double minimiseMaxDistance(vector<int>& A, int k){
	int n = A.size();
	vector<int> between(n - 1);
	priority_queue<pair<double, int>> pq;

	for (int i = 0; i < n - 1; ++i) 
		pq.push({A[i+1] - A[i], i});

	for (int gs = 1; gs <= k; ++gs) {
		auto tp = pq.top();
		pq.pop();
		int i = tp.second;
		++between[i];
		double diff = A[i+1] - A[i];
		double section = diff / (between[i] + 1);
		pq.push({section, i}); 
	}

	return pq.top().first;
}