def main():
    n, m = map(int, input().split())
    ans = 10 ** 10
    m1, m2 = m // 2, m - m // 2
    for i in range(1, n):
        S = i * m, m1 * (n - i), m2 * (n - i)
        ans = min(ans, max(S) - min(S))
    n1, n2 = n // 2, n - n // 2
    for i in range(1, m):
        S = i * n, n1 * (m - i), n2 * (m - i)
        ans = min(ans, max(S) - min(S))
    if n % 3 == 0 or m % 3 == 0: ans = 0
    if n > 2: ans = min(ans, m)
    if m > 2: ans = min(ans, n)
    assert(ans != 10 ** 10)
    print(ans)
main()