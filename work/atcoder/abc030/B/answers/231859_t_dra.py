from decimal import *

n, m = map(int, input().split())
short_one_angle = 360 // 12
long_one_angle = 360 // 60

long = m * long_one_angle
short = Decimal((n % 12) * short_one_angle + short_one_angle * m / 60)

diff = Decimal(abs(long - short))
ans = min(diff, abs(360 - diff))
print(ans)
