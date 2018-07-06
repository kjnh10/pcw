def d_LCMrush(N, K):
    MOD = 10**9 + 7
    # リストdivisorにKの約数を降順で格納する
    tmp = []
    i = 1
    while i**2 <= K:
        if K % i == 0:
            tmp.append(i)
            tmp.append(K // i)
        i += 1
    divisor = sorted(list(set(tmp)), reverse=True)

    """
    GCDがNの約数になっているものについて、LCM(i,K)の和をとる
    lcm_sum:
    GCDの値が等しい値の集合(i,K)について、LCM(i,K)の和を格納
    GCDの値が大きな集合についての計算結果から順に格納されていく
    """
    lcm_sum = [0 for _ in range(len(divisor))]
    multiply = [0 for _ in range(len(divisor))]
    ans = 0
    for i in range(len(divisor)):
        """約数を上から順にとり、その約数の倍数の和をNまで取る"""
        # 取った約数からNまで、約数の倍数は何個あるかを格納
        time = N // divisor[i]
        # 下の式の右辺第二項以降は、等差数列の和の公式
        multiply[i] = divisor[i] * time * (time + 1) // 2
        # 着目した約数より大きな約数に、着目した約数を約数に持つものがあればそれを引く
        for j in range(i):
            if divisor[j] % divisor[i] == 0:
                """
                この条件をみたす場合、divisor[j]はdivisor[i]の倍数
                そのままにしておくと同じものを2回足すことになるので、引く
                負数の剰余を取らないため、MODを足しておく
                """
                multiply[i] = (multiply[i] + MOD - multiply[j]) % MOD
        lcm_sum[i] = (multiply[i] * K // divisor[i]) % MOD

    ans = sum(lcm_sum) % MOD
    return ans

N,K = [int(i) for i in input().split()]
print(d_LCMrush(N, K))