// Time  : O(2N + Nlog(N)) - Where N is the total number of nodes in ll
// Space : O(2N)

Node* flattenLinkedList(Node* head) {
	vector<int> vals;
	Node* h = head;
	while (h) {
		Node* hh = h;
		while (hh) {
			vals.push_back(hh->data);
			hh = hh->child;
		}
		h = h->next;
	}
	sort(vals.begin(), vals.end());
	Node* dummy = new Node(0);
	h = dummy;
	for (int& n : vals) {
		h->child = new Node(n);
		h = h->child;
	}
	return dummy->child;
}

// TLE
// Time  : O(2N + Nlog(N)) - Where N is the total number of nodes in ll
// Space : O(N)

Node* flattenLinkedList(Node* head) {
	vector<int> vals;
	Node* h = head;
	while (h) {
		vals.push_back(h->data);
		if (h->child) {
			Node* next = h->next;
			while (h->child) {
				vals.push_back(h->child->data);
				h = h->child;
			}
			h->child = next;
			h = h->child;
		}
		else {
			h->child = h->next;
			h = h->child;
		}
	}
	sort(vals.begin(), vals.end());
	h = head;
	int x = 0;
	while (h) {
		h->data = vals[x];
		++x;
		h = h->child;
	}
	return head;
}