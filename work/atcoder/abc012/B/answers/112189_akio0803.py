N = int(input())

h = N // 3600
m = N % 3600 // 60
s = N % 3600 % 60

print("{0:02}:{1:02}:{2:02}".format(h, m ,s))