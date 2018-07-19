A, B, K, L = map(int, input().split(' '))
print(min(A * K, B * (K//L) + A * (K%L), B * (K//L+1)))