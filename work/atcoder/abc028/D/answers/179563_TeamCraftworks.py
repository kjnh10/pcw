import sys

def main():
    N,K = map(int,input().split())
    frac = 1
    a = K - 1
    b = N - K
    if ( a >= 1 ) and ( b <= N ) :
        frac += a * b * 6
    if a >= 1:
        frac += a * 3
    if ( b <= N ):
        frac += b * 3
    print(frac/(N*N*N))

if __name__ == "__main__":
    main()
