N = int(input())
A = list(map(int, input().split()))

prev = 0
es = []
for a in reversed(sorted(A)):
    if(prev == a):
        es.append(a)
        prev = 0
        if len(es) == 2:
            print(es[0] * es[1])
            break
    else:
        prev = a
else:
    print(0)
