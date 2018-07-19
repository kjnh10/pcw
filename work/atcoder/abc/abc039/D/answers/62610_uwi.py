import sys

stdin = sys.stdin

h,w = map(int, stdin.readline().split())
b = []
for i in range(h):
    b.append(stdin.readline().strip())

ret = []
for i in range(h):
    row = []
    for j in range(w):
        ok = True
        for k in range(-1,2):
            for l in range(-1,2):
                if 0 <= i+k < h and 0 <= j+l < w:
                    if  b[i+k][j+l] == '.': ok = False
        if ok:
            row.append("#")
        else:
            row.append(".")
    ret.append(row)
for i in range(h):
    for j in range(w):
        ex = "."
        for k in range(-1,2):
            for l in range(-1,2):
                if 0 <= i+k < h and 0 <= j+l < w:
                    if  ret[i+k][j+l] == "#": ex = "#"
        if b[i][j] != ex:
            print("impossible")
            sys.exit(0)
print("possible")
for row in ret:
    print("".join(row))
