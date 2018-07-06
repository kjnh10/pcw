import sys
sys.setrecursionlimit(5000)
def minimax(a_len,b_len,dp,turn,A,B,a_lis,b_lis):
    # print(dp[a_len][b_len],a_len,b_len)
    if dp[a_len][b_len] != -1:
        return dp[a_len][b_len]
    if turn:
        if a_len < A:
            dp[a_len][b_len] = max(dp[a_len][b_len],a_lis[a_len] + minimax(a_len+1,b_len,dp,0,A,B,a_lis,b_lis))
        if b_len < B:
            dp[a_len][b_len] = max(dp[a_len][b_len],b_lis[b_len] + minimax(a_len,b_len+1,dp,0,A,B,a_lis,b_lis))
    else:
        dp[a_len][b_len] = float("inf")
        if a_len < A:
            dp[a_len][b_len] = min(dp[a_len][b_len],minimax(a_len+1,b_len,dp,1,A,B,a_lis,b_lis))
        if b_len < B:
            dp[a_len][b_len] = min(dp[a_len][b_len],minimax(a_len,b_len+1,dp,1,A,B,a_lis,b_lis))
    return dp[a_len][b_len]
A,B = (int(n) for n in input().split(" "))
dp = [[-1 for n in range(B+1)] for m in range(A + 1)]
a_lis = [int(n) for n in input().split(" ")]
b_lis = [int(n) for n in input().split(" ")]
dp[A][B] = 0
minimax(0,0,dp,1,A,B,a_lis,b_lis)
# print(dp,a_lis,b_lis)
print(dp[0][0])
