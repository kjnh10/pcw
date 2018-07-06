W = int(input())
N, K = map(int, input().split())
wvs = [[int(x) for x in input().split()] for _ in range(N)]
wvs = [None] + sorted(wvs, reverse=True)

def dfs(i, mw, k, d={}):
    k = min(i, k)
    if k < 1:
        return 0
    if (i, mw, k) in d:
        return d[i, mw, k]
    w, v = wvs[i]
    if mw < w:
        return 0
    d[i, mw, k] = max(dfs(i - 1, mw, k), 
                      dfs(i - 1, mw - w, k-1) + v if w <= mw else 0)
    return d[i, mw, k]

print(dfs(N, W, K))