def d_cutting(A, B, N, X, Y):
    def signed_area(x1, y1, x2, y2, x3, y3):
        # 時計回りに打たれた3点(x1,y1),(x2,y2),(x3,y3)が作る三角形の面積
        # ただし、符号付き面積の符号だけわかればよいので、
        # 1/2をかけていないし、絶対値も取らない
        return (x1 - x3) * (y2 - y3) - (x2 - x3) * (y1 - y3)

    def is_crossed(i):
        # 線分(空手チョップの軌跡)からみた辺の両端が同じ側にあるなら、交差していないとする
        cond1 = signed_area(X[i], Y[i], A[0], A[1], B[0], B[1])
        cond2 = signed_area(X[(i + 1) % N], Y[(i + 1) %
                                              N], A[0], A[1], B[0], B[1])
        if cond1 * cond2 >= 0:
            return 0
        # 辺からみた線分の両端が同じ側にあるなら、交差していないとする
        cond3 = signed_area(A[0], A[1], X[i], Y[i],
                            X[(i + 1) % N], Y[(i + 1) % N])
        cond4 = signed_area(B[0], B[1], X[i], Y[i],
                            X[(i + 1) % N], Y[(i + 1) % N])
        if cond3 * cond4 >= 0:
            return 0
        # 上の条件を満たさなかった場合、線分同士交差している
        return 1

    count = 0  # 線分と辺が交差した回数
    for i in range(N):
        count += is_crossed(i)  # i番目の辺が線分と交差していたら+1
    return count // 2 + 1
  
l = [int(i) for i in input().split()]
A = [l[0],l[1]]
B = [l[2],l[3]]
N = int(input())
m = [[int(i) for i in input().split()] for _ in range(N)]
X = []
Y = []
for i in range(N):
  X.append(m[i][0])
  Y.append(m[i][1])
print(d_cutting(A, B, N, X, Y))