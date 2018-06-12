H, W = map(int, input().split())

def fun(H, W):
    ans = 1e20
    for w in range(1, W):
        w_a = (W - w) // 2
        w_b = W - w - w_a
        S1 = H * w
        ans = min(ans, max(S1, H * w_a, H * w_b) - min(S1, H * w_a, H * w_b))

        h_a = H // 2
        h_b = H - h_a
        S2 = h_a * (W - w)
        S3 = h_b * (W - w)
        ans = min(ans, max(S1, S2, S3) - min(S1, S2, S3))
    return ans

print(min(fun(H, W), fun(W, H)))
