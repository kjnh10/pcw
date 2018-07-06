N, K = map(int, input().split())
ans = ((N-K)*(K-1)*6 + 3*N - 2)/N/N/N
print(ans)