import math

if __name__ == '__main__':
    N, M = list(map(int, input().split()))

    if abs(N - M) >= 2:
        print(0)
    elif N == M:
        ans = (math.factorial(N) * math.factorial(M) * 2) % 1000000007
        print(ans)
    else:
        ans = (math.factorial(N) * math.factorial(M)) % 1000000007
        print(ans)