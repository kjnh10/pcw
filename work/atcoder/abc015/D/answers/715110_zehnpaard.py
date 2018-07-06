W = int(input())
N, K = map(int, input().split())
wvs = [[int(x) for x in input().split()] for _ in range(N)]
wvs = [(1, 0)] + sorted(wvs, reverse=True)

def dfs(i, mw, k, d={}):
    w, v = wvs[i]
    k = min(i, k, mw // w)
    if k < 1:
        return 0
    if (i, mw, k) in d:
        return d[i, mw, k]
    d[i, mw, k] = max(dfs(i - 1, mw, k), 
                      dfs(i - 1, mw - w, k - 1) + v if w <= mw else 0)
    return d[i, mw, k]

print(dfs(N, W, K))