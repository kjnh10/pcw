def solve():
    N, A, B = map(int, input().split())
    a = sorted([int(input()) for _ in [0]*N])
    min_score, max_score = a[0], a[-1]
    if max_score == min_score:
        print(-1)
        exit()
    P = B / (max_score - min_score)
    new_ave = sum(a) / N * P
    Q = A - new_ave
    print(P, Q)


if __name__ == "__main__":
    solve()