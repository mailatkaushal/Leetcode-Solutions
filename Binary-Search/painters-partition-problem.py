# Time  : O(nlogm) - Where n is len(boards), m is sum(boards) - max(boards)
# Space : O(1)

def canPaint(boards, k, time):
    painters = 1
    paintSum = 0

    for i in range(len(boards)):
        if paintSum + boards[i] <= time:
            paintSum += boards[i]
        else:
            painters += 1
            if painters > k:
                return False
            paintSum = boards[i]
    
    return True

def findLargestMinDistance(boards:list, k:int):
    n = len(boards)

    lo, hi = max(boards), sum(boards)

    while lo <= hi:
        time = lo + (hi - lo) // 2  # maximum time
        if canPaint(boards, k, time):
            hi = time - 1
        else:
            lo = time + 1

    return lo