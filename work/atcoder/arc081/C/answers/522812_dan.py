def main():
    N = int(input())
    A = list(map(int, input().split()))

    cnt = {}
    for a in A:
        if a not in cnt:
            cnt[a] = 0
        cnt[a] += 1

    B = []
    for a, x in cnt.items():
        if x >= 2:
            B.append(a)

    B = sorted(B, reverse=True)
    if len(B) > 0 and cnt[B[0]] >= 4:
        print(B[0] ** 2)
    elif len(B) > 1:
        print(B[0] * B[1])
    else:
        print('0')


if __name__ == '__main__':
    main()
