n, A, B = map(int, input().split())
l = [int(input()) for x in range(n)]

left = 0
right = 10**9


def is_ok(t):
    AB = A - B
    return sum(map(lambda x: max(0, x - B*t + (AB - 1)) // (AB), l)) <= t


while abs(left - right) > 1:
    now = (left + right) // 2
    if is_ok(now):
        right = now
    else:
        left = now

print([right, left][is_ok(left)])
