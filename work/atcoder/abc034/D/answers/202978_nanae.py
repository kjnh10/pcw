
def solve():
    def ok(mid):
        shoku = [w[i]*(p[i] - mid) for i in range(N)]
        shoku.sort(reverse=True)

        return sum(shoku[:K]) >= 0

    N, K = map(int, input().split())
    w, p = [], []

    for i in range(N):
        wi, pi = map(int, input().split())
        w.append(wi)
        p.append(pi)

    top = 100
    btm = 0

    for i in range(100):
        mid = (top + btm) / 2

        if ok(mid):
            btm = mid
        else:
            top = mid

    ans = (top + btm) / 2

    print(ans)

if __name__ == '__main__':
    solve()