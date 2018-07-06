def c_through(H, W, T, SQ):
    """
    H:マスの縦の数
    W:マスの横の数
    T:黒マス(#)を通過するのにかかる時間
    SQ:マスの情報(#:黒マス、.:白マス、S:スタート、G:ゴール)
    """
    import heapq
    for i, s in enumerate(SQ):
        if 'S' in s:
            sh = i  # スタートの縦のマス位置
            sw = s.index('S')  # スタートの横のマス位置
        if 'G' in s:
            gh = i  # ゴールの縦のマス位置
            gw = s.index('G')  # ゴールの横のマス位置

    lb, ub = 1, T  # 二分探索の下限、上限(最終的にlbが解答となる)
    for i in range(50):  # log2(10**9)が30くらいなので
        mid = (lb + ub) // 2
        square = [[float('inf')] * W for i in range(H)]
        square[sh][sw] = 0
        q = [(0, sh, sw)]  # スタート座標(到達に必要な時間0)
        f = False
        while q:
            t, h, w = heapq.heappop(q)  # 現在地点から(h,w)に到達するための時間がt
            for dh, dw in ((1, 0), (0, 1), (-1, 0), (0, -1)):
                nh, nw = (h + dh, w + dw)
                if 0 <= nh <= H - 1 and 0 <= nw <= W - 1:
                    # 次の探索予定座標がマス目の中なら、そこをd(目的地)とする
                    d = SQ[nh][nw]
                    if d == 'G':
                        f = True
                        break
                    if d == '.':
                        cnt = 1
                    else:
                        cnt = mid  # '#'マスを踏んだ場合mid秒かかるとしている
                    if t + cnt < T and square[nh][nw] > t + cnt:
                        # 上の条件を満たしていないということは、
                        # ゴールにたどり着く前に上限時間を超えたか、
                        # 別のルートをたどったほうが早いことになる。
                        square[nh][nw] = t + cnt
                        heapq.heappush(q, (t + cnt, nh, nw))
        if f:
            lb = mid  # ゴールに到達できた場合、制限時間の下限を引き上げてみる
        else:
            ub = mid  # 到達できなかった場合、上限を下げてみる
    return lb

H,W,T = [int(i) for i in input().split()]
SQ = [input() for _ in range(H)]
print(c_through(H, W, T, SQ))