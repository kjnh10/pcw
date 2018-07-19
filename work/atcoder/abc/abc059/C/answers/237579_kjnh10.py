def main():
    N = int(input())

    A = list(map(int, input().split()))

    # first positive
    sign = 1
    S = 0
    cost = 0
    for a in A:
        S += a
        if S * sign > 0:
            pass
        else:
            cost += abs(S) + 1
            S = sign
        sign *= -1
    p = cost

    # first negative
    sign = -1
    S = 0
    cost = 0
    for a in A:
        S += a
        if S * sign > 0:
            pass
        else:
            cost += abs(S) + 1
            S = sign
        sign *= -1
    q = cost

    print(min(p,q))


if __name__ == "__main__":
    main()
