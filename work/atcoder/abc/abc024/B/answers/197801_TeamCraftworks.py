import sys

def main():
    N,T = map(int,input().split())
    A = [int(input()) for _ in range(N)]
    ans,pre = 0, 0
    for v in A:
        if pre < v:
            ans += T
            pre = v + T
        else: 
            ans += ( v + T - pre )
            pre = v + T
    print(ans)

if __name__ == "__main__":
    main()
