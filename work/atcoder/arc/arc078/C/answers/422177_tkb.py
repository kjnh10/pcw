N = int(input())
a = tuple(map(int, input().split()))
arai = sum(a)-a[0]
snuke = a[0]
ans = abs(snuke-arai)
for n in a[1:-1]:
    snuke += n
    arai -= n
    diff = abs(snuke - arai)
    ans = ans if ans < diff else diff
print(ans)