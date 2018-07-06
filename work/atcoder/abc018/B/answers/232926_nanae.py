import sys

def solve():
    s = input()
    n = int(input())

    for i in range(n):
        l, r = map(int, input().split())
        l, r = l-1, r-1
        s = s[:l] + s[l:r+1][::-1] + s[r+1:]

    print(s)

if __name__ == '__main__':
    solve()