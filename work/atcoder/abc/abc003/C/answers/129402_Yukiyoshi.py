n, k = map(int, input().split())
rs = list(map(int, input().split()))

rate = 0
selected_rs = sorted(rs)[n-k:]
for r in selected_rs:
    rate = (rate + r) / 2

print(rate)
