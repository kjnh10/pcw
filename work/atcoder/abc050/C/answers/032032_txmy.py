
N = int(input())
st = input().split()
d = 10**9 + 7
A = []
m = N%2
fl = {}
exflag = False
for i in range(N):
    a = int(st[i])
    A.append(a)
    if (a + m) % 2 == 0:
        print(0)
        exflag = True
        break
    if a == 0:
        if 0 in fl.keys():
            print(0)
            exflag = True
            break
        fl[0] = 1
    else:
        if a in fl.keys():
            if fl[a] > 1:
                print(0)
                exflag = True
                break
            else:
                fl[a] = 2
        else:
            fl[a] = 1

        
if exflag == False:    
    ret = 2**(N//2) %d
    print(ret)
    