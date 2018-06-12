if __name__ == "__main__":
    N = int(input())
    if (N == 1):
        print (1)
        exit()
    res = 1 << 50
    for x in range(1, N):
        if (x * x > N):
            break
        if (N % x == 0):
            a = len(str(x))
            b = len(str(N // x))
            res = min(res, max(a, b))
    print (res)
