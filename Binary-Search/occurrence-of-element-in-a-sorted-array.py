# Time  : O(logn)
# Space : O(1)

def count(A: [int], n: int, target: int) -> int:
    lo, hi = 0, n - 1
    first = -1

    while lo <= hi:
        mid = lo + (hi - lo) // 2
        if A[mid] < target:
            lo = mid + 1
        elif A[mid] > target:
            hi = mid - 1
        else:
            first = mid
            hi = mid - 1

    lo, hi = 0, n - 1
    last = -1

    while lo <= hi:
        mid = lo + (hi - lo) // 2
        if A[mid] < target:
            lo = mid + 1
        elif A[mid] > target:
            hi = mid - 1
        else:
            last = mid
            lo = mid + 1

    if first == -1:
        return 0
    return last - first + 1