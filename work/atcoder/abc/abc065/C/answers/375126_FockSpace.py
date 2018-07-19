from math import factorial
mod = 1000000007
N, M = map(int, input().split())
if M-N>1 or M-N<-1:
    print(0)
elif M == N:
    print(2*factorial(M)**2 % mod)
else:
    print(factorial(M)*factorial(N) % mod)