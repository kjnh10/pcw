def solve():
    n, m = map(int, input().split())
    ans = 0
    ans += min(n, m // 2)
    m -= n * 2
    if m > 0:
        ans += m // 4
    print(ans)

if __name__=="__main__":
    solve()