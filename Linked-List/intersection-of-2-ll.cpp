int intersectPoint(Node* h1, Node* h2) {
    Node* a=h1;
    Node* b=h2;
    while (a!=b) {
        a=(a->next==NULL?h2:a->next);
        b=(b->next==NULL?h1:b->next);
    }
    return a->data;
}