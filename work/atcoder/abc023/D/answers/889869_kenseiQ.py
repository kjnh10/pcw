def d_shoot(N, A):
    """
    N:風船の個数
    A:風船の高度(altitude)に関する情報[初期高度H_i,1秒ごとに上昇する高度S_i]
    """
    # 二分探索する区間[left,right]
    left = 1
    right = 10**15
    time_limit = [0 for _ in range(N)] #time_limit[i]以内に風船iを割らねばならない

    while right - left > 1:
        mid = (left + right) // 2 #各風船は高さmidに到達する前に割らねばなっらない
        for i, (h, s) in enumerate(A):
            if mid < h:
                # 開始時にさえ割ることが無理
                time_limit[i] = -1
            time_limit[i] = (mid - h) // s  # 高さがmidになる前に割るために必要な時間の最大値
        time_limit = sorted(time_limit) #制限時間が短い風船から割っていく
        flag = True #制限時間内に割れるか？
        for i in range(N):
            if time_limit[i] < i:
                flag = False #割れないものが1つでもあるなら、高度がmidを越える風船があったということ

        if flag:
            right = mid
        else:
            left = mid
    return right
  
N = int(input())
A = [[int(i) for i in input().split()] for j in range(N)]
print(d_shoot(N, A))