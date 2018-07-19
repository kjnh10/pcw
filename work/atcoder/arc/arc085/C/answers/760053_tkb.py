def solve():
    N, M = map(int, input().split())
    s = ((N-M)*100+1900*M)*2**M
    print(s)


if __name__ == "__main__":
    solve()