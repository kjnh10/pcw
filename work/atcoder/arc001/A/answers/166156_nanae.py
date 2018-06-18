N = int(input())
c = input()

ans_max = 0
ans_min = N + 1

for i in range(1, 5):
    tmp = c.count(str(i))
    ans_max = max(ans_max, tmp)
    ans_min = min(ans_min, tmp)

print(ans_max, ans_min)