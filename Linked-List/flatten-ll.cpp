// Time  : O(2k+3k+4k+..+nk)=O(k+2k+3k+..+(n-1)k)=O((n-1)nk/2)~O(nnk)
Node* flatten(Node* root) {\
		Node* x=root;
		while (x->next) {
				Node*a=x;
				Node*b=a->next;
				Node*next=x->next->next;
				a->next=NULL;
				b->next=NULL;
				Node*dummy=new Node(-1);
				Node*d=dummy;
				while (a&&b) {
						if (a->data<=b->data) {
								d->bottom=a;
								a=a->bottom;
						}
						else {
								d->bottom=b;
								b=b->bottom;
						}
						d=d->bottom;
				}
				if (a) d->bottom=a;
				else d->bottom=b;
				Node* x=dummy->bottom;
				x->next=next;
		}
		return x;
}