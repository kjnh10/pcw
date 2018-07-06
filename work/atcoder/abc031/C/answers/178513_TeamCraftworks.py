import sys

def simulate(a,L,R,N):
    T = []
    for i in range(N):
        if min(L,R) <= i <= max(L,R):
            T.append(a[i])
    takahashi = 0
    aoki = 0
    M = len(T)
    for i in range(M):
        if i % 2 == 0:
            takahashi += T[i]
        else:
            aoki += T[i]
    return (takahashi,aoki)

def main():
    N = int(input())
    a = list(map(int,input().split()))
    maxi = -sys.maxsize
    for i in range(N):
        score = (-sys.maxsize,-sys.maxsize)
        for j in range(N):
            if i == j:
                continue
            v = simulate(a,i,j,N)
            if score == (-sys.maxsize,-sys.maxsize):
                score = v
            elif score[1] < v[1]:
                score = v
        maxi = max(maxi,score[0])
    print(maxi)

if __name__ == "__main__":
    main()
