n,z,w=map(int,input().split())
aa=input().split()
an=int(aa[-1])
if len(aa) > 1:
    am=int(aa[-2])
    print(max(abs(an-w),abs(an-am)))
else:
    print(abs(an-w))