import bisect

if __name__ == '__main__':
    N = int(input())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    C = list(map(int, input().split()))

    A.sort()
    C.sort()
    ans = 0
    for b in B:
        a_num = bisect.bisect_left(A, b)
        c_num = N - bisect.bisect_right(C, b)
        ans += a_num * c_num

    print(ans)
