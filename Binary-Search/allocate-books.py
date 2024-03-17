# Time  : O(n*m) - Where n is len(books), m is sum(books) - max(books)
# Space : O(1)

bool canAllocate(vector<int>& books, int n, int m, int pages) {
    int students = 1;
    int pageSum = 0;

    for (int i = 0; i < n; ++i) {
        if (pageSum + books[i] <= pages) 
            pageSum += books[i];
        else {
            ++students;
            if (students > m) 
                return false;
            pageSum = books[i]; 
        }
    }

    return true;
}

int findPages(vector<int>& books, int n, int m) {
    if (m > n) 
        return -1;

    int lo = *max_element(books.begin(), books.end());
    int hi = accumulate(books.begin(), books.end(), 0);

    for (int pages = lo; pages <= hi; ++pages) {  // maximum pages
        if (canAllocate(books, n, m, pages)) 
            return pages;
    }

    return -1;
}

# Time  : O(nlogm) - Where n is len(books), m is sum(books) - max(books)
# Space : O(1)

def canAllocate(books, n, m, pages):
    students = 1
    pageSum = 0

    for i in range(n):
        if pageSum + books[i] <= pages:
            pageSum += books[i]
        else:
            students += 1
            if students > m:
                return False
            pageSum = books[i]
    
    return True

def findPages(books: [int], n: int, m: int) -> int:
    if m > n:
        return -1

    lo, hi = max(books), sum(books)

    while lo <= hi:
        pages = lo + (hi - lo) // 2  # maximum pages 
        if canAllocate(books, n, m, pages):
            hi = pages - 1
        else:
            lo = pages + 1
        
    return lo