n = int(input())
h = n // 3600
m = n // 60 % 60
s = n % 60
print("{0:0>2}:{1:0>2}:{2:0>2}".format(h, m, s))
