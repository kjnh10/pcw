from collections import defaultdict


def main():
    N, M = map(int, input().split())
    A, B = [], []
    for _ in range(N):
        a = input()
        A.append(a)
    for _ in range(M):
        b = input()
        B.append(b)

    for y in range(N):
        for x in range(N):

            ok = True
            for ys in range(M):
                for xs in range(M):
                    if y + ys < N and x + xs < N:
                        if A[y + ys][x + xs] == B[ys][xs]:
                            pass
                        else:
                            ok = False
                    else:
                        ok = False

            if ok:
                print("Yes")
                return
    print("No")


if __name__ == '__main__':
    main()
