A, B, C = list(map(int, input().split()))

m = max(A, B, C)
diff = [m - A, m - B, m - C]
s = sum(diff)
if s % 2 == 0:
    print(s // 2)
else:
    print((s + 3) // 2)
