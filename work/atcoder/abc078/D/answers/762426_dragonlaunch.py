n,z,w = [int(i) for i in input().split()]
a = list(int(i) for i in input().split())
#print(a)
abs1 = abs(a[n-1] - w)
abs2 = abs(a[n-2]-a[n-1])
print(max(abs1,abs2))
