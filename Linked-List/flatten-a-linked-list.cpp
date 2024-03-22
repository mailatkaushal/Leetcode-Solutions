// Time  : O(2nk + nklog(nk)) - Where n denotes the size of the ll & k is the average number of child nodes for each of the n nodes 
// Space : O(2nk)

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

// Time  : O(2k+3k+4k+..+nk) = O(k+2k+3k+..+(n-1)k) = O((n-1)nk/2) = O(nnk)
// Space : O(n)

Node* merge(Node* a, Node* b) {
	Node* dummy = new Node();
	Node* h = dummy;
	while (a && b) {
		if (a->data <= b->data) {
			h->child = a;
			a = a->child;
		}
		else {
			h->child = b;
			b = b->child;
		}
		h = h->child;
		// h->next = nullptr; 
	}
	if (a) h->child = a;
	else h->child = b;
	return dummy->child;
}

Node* flattenLinkedList(Node* head) {
	if (head == nullptr || head->next == nullptr) 
		return head;
	head->next = flattenLinkedList(head->next);
	return merge(head, head->next);
}