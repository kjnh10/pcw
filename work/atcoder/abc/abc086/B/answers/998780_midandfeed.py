# ===================================
# (c) MidAndFeed aka ASilentVoice
# ===================================
import math, fractions, collections
# ===================================
a, b = [str(x) for x in input().split()]
ans = int(a+b)
t = math.sqrt(ans)
print("Yes" if t == math.floor(t) else "No")