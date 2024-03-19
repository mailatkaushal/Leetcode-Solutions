// Time  : O(k)
// SPace : O(1)

#include<bits/stdc++.h>
int kthElement(vector<int>& A, vector<int>& B, int m, int n, int k){
    int i = 0, j = 0;
    int x = 0;
    int kthElement = -1;

    while (i < m && j < n) {
        if (kthElement != -1)
            break;
        if (A[i] < B[j]) {
            if (x == k - 1)
                kthElement = A[i];
            ++i;
        }
        else {
            if (x == k - 1)
                kthElement = B[j];
            ++j;
        }
        ++x;
    }

    while (i < m) {
        if (kthElement != -1)
            break;
        if (x == k - 1)
            kthElement = A[i];
        ++i;
        ++x;
    }

    while (j < n) {
        if (kthElement != -1)
            break;
        if (x == k - 1)
            kthElement = B[j];
        ++j;
        ++x;
    }

    return kthElement;
}

// Time  : O(log(min(m, n)))
// SPace : O(1)

#include<bits/stdc++.h>
int kthElement(vector<int>& A, vector<int>& B, int m, int n, int k){
    if (m > n)
        return kthElement(B, A, n, m, k);

    int lo = max(0, k - n), hi = min(k, m);

    while (lo <= hi) {
        int mid1 = (lo + hi) >> 1;
        int mid2 = k - mid1;

        int l1 = mid1 > 0 ? A[mid1 - 1] : INT_MIN;
        int l2 = mid2 > 0 ? B[mid2 - 1] : INT_MIN;
        int r1 = mid1 < m ? A[mid1] : INT_MAX;
        int r2 = mid2 < n ? B[mid2] : INT_MAX;

        if (l1 <= r2 && l2 <= r1) {
            return max(l1, l2);
        }
        else if (l1 > r2)
            hi = mid1 - 1;
        else
            lo = mid1 + 1;
    }

    return -1;
}