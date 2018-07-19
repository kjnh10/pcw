def d_valentine(N, M, P, Q, R, C):
    """
    N:女子の人数
    M:男子の人数
    P,Q:女子P人、男子Q人からなるグループを作る
    R:N人の女子が持っているチョコレートの個数
    C:チョコレートに関する情報
      (持っている女子の出席番号,渡したい男子の出席番号,渡せた場合の幸福度)
    """
    from itertools import combinations

    # choco[i][j]には、i+1番の女子がj+1番の男子にチョコを渡せたときの幸福度を格納
    choco = [[0] * M for _ in range(N)]
    for row in C:
        choco[row[0] - 1][row[1] - 1] = row[2]

    ans = 0
    for girl in combinations(range(N), P):
         # target[j]は、girlのグループにj番目の男子を入れたときの幸福度の和
        target = [0] * M
        for i in girl:
            for j in range(M):
                target[j] += choco[i][j]
        # 幸福度を高くする男子を上からQ人貪欲に取ればよい
        ans = max(ans, sum(sorted(target, reverse=True)[:Q]))
    return ans
N,M,P,Q,R = [int(i) for i in input().split()]
C = [[int(i) for i in input().split()] for j in range(R)]
print(d_valentine(N, M, P, Q, R, C))