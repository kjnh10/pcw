n,x = (int(i) for i in input().split())
m = [int(input()) for i in range(n)]
m.sort()
x -= sum(m)
print(n+(x-x%m[0])//m[0])
