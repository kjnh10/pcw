A, B = list(map(int, input().split()))
S = input()
def judge(A, B, S):
    if S[A] != '-':
        return False
    S = S[:A] + S[A+1:]
    num = '0123456789'
    for x in S:
        if x not in num:
            return False
    return True

if judge(A, B, S):
    print("Yes")
else:
    print("No")

