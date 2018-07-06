from datetime import timedelta
n = int(input())
t = str(timedelta(seconds=n))
print(t if n >= 36000 else "0" + t)
