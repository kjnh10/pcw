n,m=map(int,input().split())
x = (n%12)*5 + m/12
y = m
d=(x-y)*6
d=((d%360)+360)%360
print(min(d, 360-d))