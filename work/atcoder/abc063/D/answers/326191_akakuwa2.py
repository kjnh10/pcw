import bisect
import heapq
import math
N,A,B =list(map(int,input().split()))
h = [ int(input()) for _ in range(N)]
h.sort()


sp_damage = A-B
"""
heap = []
for hval in h:
    heapq.heappush(heap,-hval)
count = 0
while True:
    if heap[0]  >= -count*B:
        break
    count+=1
    hp = heapq.heappop(heap)
    hp += sp_damage
    heapq.heappush(heap,hp)
print(count)

"""
def nibun(func ,min_ ,max_ ):
    left = min_
    right= max_
    while not(left==right):
        mid = (left+right) //2
        tmp = func(mid)
        if tmp:
            right = mid
        else:
            left = mid+1
    return left

def check(num):
    i = num
    for hval in h:
        rest = hval-B*num
        if rest <= 0 :
            continue
        i -= math.ceil(rest/sp_damage)
        #print(rest,i)
        # sp * m + B*hval
    return i>=0

print(nibun(check,0,1000000000))

