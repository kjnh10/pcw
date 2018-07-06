def main():
    N = int(input())
    A, B = map(int, input().split())
    K = int(input())
    P = list(map(int, input().split()))

    route = tuple(sorted(P[:] + [A, B]))
    dup = tuple(sorted(set(route)))

    ans = 'YES' if route == dup else 'NO'
    print(ans)

main()
