def solve():
    import sys
    readline = sys.stdin.readline
    N = int(input())
    a = [int(readline()) for _ in [0]*N]
    a1, a2 = [0]*N, [0]*N
    for i, (n1, n2, rn1, rn2) in enumerate(zip(a, a[1:], a[::-1], a[-2::-1]), start=1):
        a1[i] = a1[i-1] + 1 if n2 > n1 else 0
        a2[-i-1] = a2[-i] + 1 if rn2 > rn1 else 0

    print(max([a+b for a, b in zip(a1, a2)]) + 1)


if __name__ == "__main__":
    solve()