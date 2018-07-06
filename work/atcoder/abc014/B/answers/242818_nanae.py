import sys

def solve():
    n, x = map(int, input().split())
    a = [int(i) for i in input().split()]

    ans = sum(ai for i, ai in enumerate(a) if x & (1 << i))
    
    print(ans)

if __name__ == '__main__':
    solve()