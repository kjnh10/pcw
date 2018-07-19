def solve(s):
    n = len(s)

    if n == 1:
        return 1
    if n == 2:
        return 2 if s[0] == s[1] else 1

    ci = n // 2
    c = s[ci]
    if n & 1:
        for di in range(1, ci + 1):
            if c == s[ci - di] == s[ci + di]:
                pass
            else:
                return ci + di
        return n
    if c != s[ci - 1]:
        return ci
    for di in range(1, ci):
        if c == s[ci - di - 1] == s[ci + di]:
            pass
        else:
            return ci + di
    return n


print(solve(input()))
