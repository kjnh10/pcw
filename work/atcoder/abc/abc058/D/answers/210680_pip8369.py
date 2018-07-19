import sys
tmp = sys.stdin.readline().strip().split(" ")
n = int(tmp[0])
m = int(tmp[1])
xs = sys.stdin.readline().strip().split(" ")
ys = sys.stdin.readline().strip().split(" ")

s_x=0
s_y=0
r = pow(10,9)+7

for i in range(1,n+1):
	s_x = (s_x + (2*i-1-n)*int(xs[i-1])) % r

for i in range(1,m+1):
	s_y = s_y + (2*i-1-m)*int(ys[i-1]) % r

print((s_x*s_y)%r)
