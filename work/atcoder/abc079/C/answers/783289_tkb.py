def solve():
    from itertools import product
    a = list(map(int, input()))
    op = ["-","+"]
    for op1, op2, op3 in product([-1, 1], [-1, 1], [-1, 1]):
        if a[0] + a[1]*op1 + a[2]*op2 + a[3]*op3 == 7:
            print("%d%s%d%s%d%s%d=7"%(a[0],op[op1==1],a[1],op[op2==1],a[2],op[op3==1],a[3]))
            exit()


if __name__ == "__main__":
    solve()