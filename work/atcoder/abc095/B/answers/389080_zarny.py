def main():
    N, X = list(map(int, input().split()))

    M = []
    for _ in range(N):
        M.append(int(input()))

    X -= sum(M)
    ans = len(M)
    min_m = min(M)

    ans += X // min_m

    print(ans)


main()
