def get_2div(v):
    while v % 2 == 0:
        v //= 2
    return v

N = int(input())
res = set()
for iv in map(lambda x:get_2div(int(x)), input().split()):
    res.add(iv)
print(len(res))
