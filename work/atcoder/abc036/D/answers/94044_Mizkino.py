from collections import defaultdict as dd

N = int(input())
br = dd(list)
dp = [[-1 for j in range(2)] for i in range(N+1)]
MOD = 10**9 +7
def nuripattern(pos,pre,ago):
    if dp[pos][pre] >= 0:
        return dp[pos][pre]
    if pre == 1:
        res = 1
        for nex in br[pos]:
            if nex == ago: continue;
            res *= nuripattern(nex,0,pos)
        dp[pos][1] = res%MOD
        return res%MOD

    else:
        res = 1
        for nex in br[pos]:
            tres = 0
            if nex == ago: continue;
            tres += nuripattern(nex,0,pos)
            tres += nuripattern(nex,1,pos)
            res *= tres
        dp[pos][0] = res%MOD
        return res%MOD

for n in range(N-1):
    a,b = map(int,input().split(" "))
    br[a].append(b)
    br[b].append(a)

print((nuripattern(1,0,0)+nuripattern(1,1,0))%MOD)
