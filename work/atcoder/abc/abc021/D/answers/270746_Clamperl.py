def comb(n,k,p):
	from math import factorial
	if n<0 or k<0 or n<k: return 0
	if n==0 or k==0: return 1
	a,b,c = factorial(n)%p,factorial(k)%p,factorial(n-k)%p
	return (a*power_func(b,p-2,p)*power_func(c,p-2,p))%p
def power_func(a,b,p):
	if b==0: return 1
	elif b%2==0:
		d = power_func(a,b//2,p)
		return d**2 %p
	elif b%2==1: return (a*power_func(a,b-1,p))%p
n = int(input())
k = int(input())
print(comb(n+k-1,k,10**9+7))