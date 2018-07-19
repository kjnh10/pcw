def solve(n, y):
    tmp1000 = n * 1000
    if tmp1000 > y:
        return -1, -1, -1
    diff = y - tmp1000
    for y in range(diff // 4000 + 1):
        tmp5000 = y * 4000
        if diff - tmp5000 < 0:
            break
        if (diff - tmp5000) % 9000 == 0:
            x = (diff - tmp5000) // 9000
            if x >= 0 and x + y <= n:
                return x, y, n - x - y
    return -1, -1, -1


print(*solve(*map(int, input().split())))
