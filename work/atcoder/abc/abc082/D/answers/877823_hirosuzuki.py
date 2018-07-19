import sys

def check(s, x, y):

    while s and s[0] == "F":
        s = s[1:]
        x -= 1
    while s and s[-1] == "T":
        s = s[:-1]

    d = 0
    vxs = []
    vys = []
    while s:
        while s and s[0] == "T":
            s = s[1:]
            d ^= 1
        l = 0
        while s and s[0] == "F":
            s = s[1:]
            l += 1
        if d:
            vys.append(l)
        else:
            vxs.append(l)

    def check1(vs, t):
        a = 0
        for v in sorted(vs, reverse=True):
            if t < a:
                a -= v
            else:
                a += v
        return a == t

    r = check1(vxs, x) and check1(vys, y)
    return r

if __name__ == "__main__":
    s = sys.stdin.readline().strip()
    x, y = [int(n) for n in sys.stdin.readline().strip().split()]
    if check(s, x, y):
        print("Yes")
    else:
        print("No")
