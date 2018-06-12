# coding: utf-8
# Your code here!

def sum_digits(n,m):
   r = 0
   while n:
       r, n = r + n % m, n // m
   return r


N=int(input())

ans = 100000
for i in range(N+1):
    ans = min(ans, sum_digits(i,6)+sum_digits(N-i,9))

print(ans)    
