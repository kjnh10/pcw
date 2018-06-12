
def main():
    n, x = map(int, input().split())
    al = list(map(int, input().split()))
    ans = 0
    for i in range(n - 1):
        l, r = i, i + 1
        exc = al[l] + al[r] - x
        if exc <= 0:
            continue
        rd = min(al[r], exc)
        al[r] -= rd
        ans += rd
        exc -= rd
        if exc > 0:
            al[l] -= exc
            ans += exc
    print(ans)


if __name__ == '__main__':
    main()