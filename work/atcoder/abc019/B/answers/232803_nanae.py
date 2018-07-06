import sys

def solve():
    s = input() + '#'
    ans = s[0]
    pch = s[0]
    cnt = 1

    for ch in s[1:]:
        if ch != pch:
            ans += str(cnt) + ch
            cnt = 1
            pch = ch
        else:
            cnt += 1

    ans = ans.rstrip('#')

    print(ans)

if __name__ == '__main__':
    solve()