n,m = map(int, input().split(' '))
x = list(map(int, input().split(' ')))
y = list(map(int, input().split(' ')))

x = [x[i+1]-x[i] for i in range(len(x)-1)]
y = [y[i+1]-y[i] for i in range(len(y)-1)]

total_x =0
for i in range(n-1):
    buf = min([i+1,n-1-i])
    buf = buf*(n-1)-buf*buf+buf
    total_x += x[i]*buf
    total_x %= 1000000007


total_y =0
for i in range(m-1):
    buf = min([i+1,m-1-i])
    buf = buf*(m-1)-buf*buf+buf
    total_y += y[i]*buf
    total_y %= 1000000007

print(total_x*total_y%1000000007)
