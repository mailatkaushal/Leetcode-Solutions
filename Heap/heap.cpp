#include <bits/stdc++.h>
using namespace std;
class Heap {
public:
    vector<int> A;
    void insert(int val) {
        A.push_back(val);
        int i=A.size()-1;
        while (i>0) {
            int par=(i-1)/2;
            if (A[i]>A[par]) {
                swap(A[i],A[par]);
                i=par;
            }
            else break;
        }
    }
    void remove() {
        if (A.size()==0) return;
        A[0]=A.back();
        A.pop_back();
        heapify(0);
    }
    void heapify(int i) {
        int largest=i;
        int left=2*i+1;
        int right=2*i+2;
        if (left<A.size() && A[largest]<A[left]) largest=left;
        if (right<A.size() && A[largest]<A[right]) largest=right;
        if (i!=largest) {
            swap(A[i],A[largest]);
            heapify(largest);
        }
    }
    void print() {
        for (int a:A) cout<<a<<" ";
        cout<<endl;
    }
};