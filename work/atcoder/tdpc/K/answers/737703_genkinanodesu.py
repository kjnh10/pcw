import bisect
N = int(input())
intervals = []
for i in range(N):
    x,r = map(int, input().split())
    intervals.append([x-r, x+r])
intervals.sort(key = lambda x: (-x[0], -x[1]))

right = [intervals[0][1]]
for interval in intervals:
    if right[-1] < interval[1]:
        right.append(interval[1])
    else:
        index = bisect.bisect_left(right, interval[1])
        right[index] = interval[1]
print(len(right))
