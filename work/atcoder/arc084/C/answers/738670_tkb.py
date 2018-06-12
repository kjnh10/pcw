def solve():
    from bisect import bisect_left
    N = int(input())
    A = sorted(map(int, input().split()))
    B = sorted(map(int, input().split()))
    C = sorted(map(int, input().split()))
    b_cumsum = [0]*(N+1)
    a_cumsum = [0]*(N+1)

    for c in C:
        bi = bisect_left(B, c)
        b_cumsum[0] += 1
        b_cumsum[bi] -= 1

    for i in range(1, N):
        b_cumsum[i] += b_cumsum[i-1]

    for b, n in zip(B, b_cumsum):
        ai = bisect_left(A, b)
        a_cumsum[0] += n
        a_cumsum[ai] -= n

    for i in range(1, N):
        a_cumsum[i] += a_cumsum[i-1]

    print(sum(a_cumsum[:-1]))


if __name__ == "__main__":
    solve()