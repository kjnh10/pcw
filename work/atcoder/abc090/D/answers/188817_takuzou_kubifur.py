nk = input().split()
n = int(nk[0])
k = int(nk[1])

cnt = 0
for b in range(n):
    if b+1 > k:
        cnt += (n // (b+1)) * (b+1 - k)
    if n % (b+1) >= max(k,1):
        if k > 0:
            cnt += n % (b+1) - k + 1
        else:
            cnt += n % (b+1)

        

print(cnt)