N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
C = list(map(int, input().split()))
c = 0
Acount = [0] * len(A)
Bcount = [0] * len(B)
count = 0
A = sorted(A, reverse=True)
B = sorted(B, reverse=True)
C = sorted(C, reverse=True)

for b in range(len(B)):
    Bcount[b] = count
    if c < len(C):
        while B[b] < C[c]:
            c += 1
            Bcount[b] += 1
            if c == len(C):
                break
        count = Bcount[b]
b = 0
count = 0
for a in range(len(A)):
    Acount[a] = count
    if b < len(B):
        while A[a] < B[b]:
            Acount[a] += Bcount[b]
            b += 1
            if b == len(B):
                break
        count = Acount[a]

print(sum(Acount))