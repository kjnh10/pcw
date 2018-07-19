if __name__ == '__main__':
    N,M = map(int, input().split())
    data = []
    for i in range(N):
        a,b = map(int, input().split())
        data.append([a, b])
    checks = []
    for i in range(M):
        c,d = map(int, input().split())
        checks.append([c, d])

    for a,b in data:
        res = 1 << 50
        p = -1
        for idx, check in enumerate(checks):
            tmp = abs(a - check[0]) + abs(b - check[1])
            if (tmp < res):
                res = tmp
                p = idx + 1
        print (p)
