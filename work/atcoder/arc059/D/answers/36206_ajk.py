S=input()
N=len(S)
A,B=-1,-1
for i in range(N-1):
    if S[i] == S[i+1]:
        A,B=i+1,i+2
for i in range(N-2):
    if S[i] == S[i+2]:
        A,B=i+1,i+3
print(A,B)