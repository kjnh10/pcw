N = int(input())
A = list(map(int, input().split()))
Ai = max(A)
x = float('inf')
for a in A:
    if abs((Ai - a) - a) <= x:
        x = abs((Ai - a) - a)
        Aj = a
print(Ai, Aj)