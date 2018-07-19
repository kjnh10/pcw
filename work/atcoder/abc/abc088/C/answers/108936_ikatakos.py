def solve():
    if not (c11 - c21 == c12 - c22 == c13 - c23):
        return False
    if not (c11 - c31 == c12 - c32 == c13 - c33):
        return False
    if not (c11 - c12 == c21 - c22 == c31 - c32):
        return False
    if not (c11 - c13 == c21 - c23 == c31 - c33):
        return False
    return True


c11, c12, c13 = map(int, input().split())
c21, c22, c23 = map(int, input().split())
c31, c32, c33 = map(int, input().split())

print('Yes' if solve() else 'No')
