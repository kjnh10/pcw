def d_People_on_a_Line(N, M, P):
    if M == 0:
        return 'Yes'

    adj = [[] for _ in range(N)]  # 隣接リスト
    for l, r, d in P:
        adj[l - 1].append([r - 1, d])
        adj[r - 1].append([l - 1, -d])

    dist = [None for _ in range(N)]
    for i in range(N):  # グラフが非連結なこともあるので、全頂点を始点として試す
        if dist[i] is not None:
            # 値が決定済み
            continue
        stack = [i]
        dist[i] = 0  # 始点の距離は0
        while stack:
            v = stack.pop()  # 訪れる頂点
            for to, cost in adj[v]:
                if dist[to] is None:
                    # 頂点toが未決定なら、そこを次に訪れる頂点とする
                    stack.append(to)
                    dist[to] = dist[v] + cost
                elif dist[to] != dist[v] + cost:
                    # 値が決定済みの頂点に合流し、
                    # 与えられた情報と矛盾した
                    return 'No'
    return 'Yes'  # 全頂点で矛盾しなかった

N,M = [int(i) for i in input().split()]
P = [[int(i) for i in input().split()] for j in range(M)]
print(d_People_on_a_Line(N, M, P))