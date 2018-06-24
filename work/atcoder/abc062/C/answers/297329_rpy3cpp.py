H, W = map(int, input().split())

def solve(H, W):
    if H % 3 == 0 or W % 3 == 0:
        return 0
    # 横３分割または縦３分割
    record = min(H, W)

    #  ##&
    #  **&
    # (H // 2) * x
    # (H - H // 2) * x
    # (W - x) * H
    
    
    xt = (W // 3) * 2
    for x in range(max(1, xt - 100), min(W, xt + 100)):
        a1 = (H//2) * x
        a2 = H * x - a1
        a3 = (W - x) * H
        dif = max(a1, a2, a3) - min(a1, a2, a3)
        if dif < record:
            record = dif
    
    H, W = W, H
    xt = (W // 3) * 2
    for x in range(max(1, xt - 100), min(W, xt + 100)):
        a1 = (H//2) * x
        a2 = H * x - a1
        a3 = (W - x) * H
        dif = max(a1, a2, a3) - min(a1, a2, a3)
        if dif < record:
            record = dif
    
    return record

print(solve(H, W))