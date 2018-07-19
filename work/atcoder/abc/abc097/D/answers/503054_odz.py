def main():
    n, m = map(int, input().split())
    p = map(int, input().split())
    trans = []

    for _ in range(m):
        x, y = map(int, input().split())
        trans.append((x, y))
    
    ss = dict()

    for t in trans:
        x, y = t
        xs = ss.get(x, None)
        ys = ss.get(y, None)

        if xs is None and ys is None:
            zs = set([x, y])
            ss[x] = zs
            ss[y] = zs
        elif xs is not None and ys is None:
            xs.add(y)
            ss[y] = xs
        elif xs is None and ys is not None:
            ys.add(x)
            ss[x] = ys
        else:
            if id(xs) == id(ys):
                continue

            if len(xs) >= len(ys):
                for yy in ys:
                    ss[yy] = xs
                    xs.add(yy)
            else:
                for xx in xs:
                    ss[xx] = ys
                    ys.add(xx)

    c = 0
    for i, v in enumerate(p, 1):
        if i == v:
            c += 1
        elif i in ss and v in ss[i]:
            c += 1
    print(c)

main()