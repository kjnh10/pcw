from collections import Counter
from math import factorial
n = int(input())
t = [int(input()) for i in range(n)]
t.sort()
answer,ans = 0,1
for i in range(n): answer += (n-i)*t[i]
print(answer)
c = Counter(t).most_common()
for i in c:
	if i[1]==1: break
	ans = (ans*factorial(i[1]))%(10**9+7)
print(ans)