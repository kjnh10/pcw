import itertools
N = int(input())
s = list(input())

def hantei(N,s):
    for onetwo in itertools.product((0, 1), (0, 1)):
        res = {}
        for n in range(N):
            if n == 0:
                res[n] = onetwo[0]
            elif n == 1:
                res[n] = onetwo[1]
            else:
                if res[n-1] == 0 and s[n-1] == "o":
                    res[n] = res[n-2]
                elif res[n-1] == 0 and s[n-1] == "x":
                    res[n] = 1 if res[n-2] == 0 else 0
                elif res[n-1] == 1 and s[n-1] == "o":
                    res[n] = 1 if res[n-2] == 0 else 0
                elif res[n-1] == 1 and s[n-1] == "x":
                    res[n] = res[n-2]
        # check s[0]
        if (res[1] == res[N-1]) and res[0] == 0 and s[0] == "x":
            continue
        if (res[1] == res[N-1]) and res[0] == 1 and s[0] == "o":
            continue
        if (res[1] != res[N-1]) and res[0] == 0 and s[0] == "o":
            continue
        if (res[1] != res[N-1]) and res[0] == 1 and s[0] == "x":
            continue
        # check s[n-1]
        if (res[0] == res[N-2]) and res[N-1] == 0 and s[N-1] == "x":
            continue
        if (res[0] == res[N-2]) and res[N-1] == 1 and s[N-1] == "o":
            continue
        if (res[0] != res[N-2]) and res[N-1] == 0 and s[N-1] == "o":
            continue
        if (res[0] != res[N-2]) and res[N-1] == 1 and s[N-1] == "x":
            continue

        print(''.join(map(lambda x: "S" if x == 0 else "W", res.values())))
        return True

    return False

if not hantei(N, s):
    print(-1)
    
        
