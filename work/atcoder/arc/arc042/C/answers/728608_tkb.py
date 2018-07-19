def solve():
    import sys
    readline = sys.stdin.readline
    N, M = map(int, input().split())
    a = [int(readline()) for _ in [0]*M]
    _set, result = set(), []
    add, append = _set.add, result.append
    for n in a[::-1]:
        if n not in _set:
            append(n)
            add(n)
    for i in range(1, N+1):
        if i not in _set:
            append(i)

    print("\n".join(map(str, result)))


if __name__ == "__main__":
    solve()