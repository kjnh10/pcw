N = int(input())
As = list(map(int, input().split()))

def solve(N, As):
    total = sum(As)
    record = abs(total - As[0] - As[0])
    cum = 0
    for a in As[:-1]:
        cum += a
        record = min(record, abs(total - cum - cum))
    return record

print(solve(N, As))
