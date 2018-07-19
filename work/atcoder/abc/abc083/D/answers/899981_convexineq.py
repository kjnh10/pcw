# coding: utf-8
# Your code here!
S=[int(i) for i in input()]
L = len(S)


if L%2 == 1:
    mid = (L-1)//2
    midnum = S[mid]
    a = 0
    while mid-a != -1 and S[mid-a] == S[mid+a] == midnum:
        a += 1
    print(mid+a)
else:
    mid = (L-1)//2
    midnum1 = S[mid]
    midnum2 = S[mid+1]
    a = 0
    while mid-a != -1 and S[mid-a] == S[mid+1+a] == midnum1 == midnum2:
        a += 1
    print(mid+a+1)