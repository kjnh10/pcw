N, L = map(int,input().split())
S = [str(input()) for _ in range(N)]
S.sort()
print("".join(S))