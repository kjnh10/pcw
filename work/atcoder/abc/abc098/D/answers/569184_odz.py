def main():
    n = int(input())
    a = list(map(int, input().split()))
    print(resolve(a))

def resolve(a):
    cnt = 0
    base = 0
    skip = 0

    for i in range(len(a)):
        c, base = resolve_1(a, i, skip, base)

        skip = c - 1
        base = base ^ a[i]
        cnt += c

    
    return cnt

def resolve_1(a, i, skip, base):
    cnt = skip

    for j in range(i + skip, len(a)):
        if a[j] & base != 0:
            break
        
        cnt += 1
        base |= a[j]

    return (cnt, base)

main()