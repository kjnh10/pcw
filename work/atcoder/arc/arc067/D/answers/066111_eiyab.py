def iter2(it):
    x = iter(it)
    before = next(x)
    for item in x:
        yield before, item
        before = item

N, A, B = map(int, input().split())
xs = list(map(int, input().split()))

costs = (min(B, A*(x2-x1)) for x1, x2 in iter2(xs))
print(sum(costs))