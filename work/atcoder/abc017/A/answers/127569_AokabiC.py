def rren(): return list(map(int, input().split()))

score = 0
for i in range(3):
    max, rate = rren()
    score += max*0.1*rate

print(int(score))
