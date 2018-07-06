N, W, C = map(int, input().split())
_items = [tuple(map(int, input().split())) for _ in [0]*N]
all_items = dict()
for w, v, c in _items:
    if c in all_items:
        all_items[c].append((w, v))
    else:
        all_items[c] = [(w, v)]

dp = [[0] * (W + 1) for _ in [0] * C]

max_color = len(all_items)
_weights = [set() for _ in range(C)]

for i, items in enumerate(all_items.items()):
    for j in range(min(i, C - 1), max(-1, C-(max_color-i)-1), -1):
        if j == 0:
            _dp = [0] * (W + 1)
            weights = {0}
        else:
            _dp = dp[j - 1].copy()
            weights = _weights[j - 1].copy()
        add = weights.add

        for w, v in items[1]:
            for k in sorted(weights, reverse=True):
                if k + w <= W and _dp[k] + v > _dp[k + w]:
                    _dp[k + w] = _dp[k] + v
                    add(k + w)

        cdp = dp[j]
        for k in weights:
            if cdp[k] < _dp[k]:
                cdp[k] = _dp[k]

        _weights[j] = _weights[j].union(weights)

print(max(dp[-1]))