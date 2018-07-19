def D_SmallMultiple(K):
    import collections
    q = collections.deque()
    q.append(1)  # 頂点1からスタート

    # dp[i]は1からi(0以上K未満)へ行くために必要なコスト(必要なのはdp[0])
    dp = [float('Inf') for _ in range(K)]
    dp[1] = 0

    while q:
        u = q.popleft()
        # 位置uから行ける場所を検索
        if dp[(u * 10) % K] > dp[u]:
            # コスト0(*10すること)で行ける場所
            dp[(u * 10) % K] = dp[u]
            q.appendleft((u * 10) % K)
        if dp[(u + 1) % K] > dp[u] + 1:
            # コスト1(+1すること)で行ける場所
            dp[(u + 1) % K] = dp[u] + 1
            q.append((u + 1) % K)
    return dp[0] + 1

K = int(input())
print(D_SmallMultiple(K))