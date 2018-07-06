def d_supplement(N, M, F):
    """
    N:サプリメントの数
    M:サプリメントの味の種類
    F:要素iの値はi番目のサプリメントの味(1-origin)
    """
    MOD = 10**9 + 7

    """
    dp[i] = dp[i-1] + dp[i-2] + ... + dp[k]
    kは F[j+1], F[j+2], ..., F[i] をすべて1日で摂取できるようなjのうち最小のもの。
    """
    dp = [0] * (N + 1)
    dp[0] = 1  # 最初は"何も食べていない"1通り

    num = [0] * (M + 1)  # 尺取の区間内での、サプリの味ごとの個数
    left = 0  # 上のdpのコメントにおけるkの役割
    sum = dp[0]

    for i in range(N):
        num[F[i]] += 1
        # 区間内に含まれる同じ味のサプリメント個数が1つになるまでdpの左端を縮める
        while num[F[i]] > 1:
            num[F[left]] -= 1
            sum -= dp[left]
            if sum < 0:
                sum += MOD
            sum %= MOD
            left += 1
        dp[i + 1] = sum
        sum += dp[i + 1]
        sum %= MOD
    return dp[-1]
  
N,M = [int(i) for i in input().split()]
F = [int(input()) for _ in range(N)]
print(d_supplement(N, M, F))