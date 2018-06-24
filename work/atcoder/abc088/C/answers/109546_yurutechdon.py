
def solve(c):
    def check(xs):
        xs = [[e - es[0] for e in es] for es in xs]
        return xs[0] == xs[1] and xs[0] == xs[2]
    return check(c) and check(list(zip(*c)))

c = [[int(_) for _ in input().split()] for i in range(3)]

if solve(c):
    print("Yes")
else:
    print("No")
